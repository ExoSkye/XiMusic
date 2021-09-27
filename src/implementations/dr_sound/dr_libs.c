#include <audioLoader.h>
#define DR_MP3_IMPLEMENTATION
#define DR_WAV_IMPLEMENTATION
#define DR_FLAC_IMPLEMENTATION
#include <dr_wav.h>
#include <dr_mp3.h>
#include <dr_flac.h>
#include <malloc.h>

float* data = NULL;
size_t length = 0;
size_t numFrames = 0;
uint32_t divisor = 0;
uint32_t cur_chunk = 0;
int rate = 0;
int channels = 0;
audioType cur_filetype = AT_NONE;

loaderError p_loadFlac(sds name) {
    drflac* flac = drflac_open_file(name, NULL);
    if (flac == NULL) {
        return AL_CANT_LOAD_FILE;
    }

    int count = 0;

    length = ((size_t)flac->totalPCMFrameCount * flac->channels * sizeof(float));

    numFrames = flac->totalPCMFrameCount;

    do {
        count++;
        divisor++;
        data = malloc(length/divisor);
        if (count == 64) {
            return AL_CANT_LOAD_FILE;
        }
    }
    while (data == NULL);

    drflac_read_pcm_frames_f32(flac, flac->totalPCMFrameCount/divisor, data);

    rate = flac->sampleRate;
    channels = flac->channels;

    return AL_NO_ERROR;
}

loaderError p_loadWav(sds name) {
    drwav wav;
    if (!drwav_init_file(&wav, name, NULL)) {
        return AL_CANT_LOAD_FILE;
    }

    int count = 0;

    length = ((size_t)wav.totalPCMFrameCount * wav.channels * sizeof(float));

    numFrames = wav.totalPCMFrameCount;

    do {
        count++;
        divisor++;
        data = malloc(length/divisor);
        if (count == 64) {
            return AL_CANT_LOAD_FILE;
        }
    }
    while (data == NULL);

    drwav_read_pcm_frames_f32(&wav, wav.totalPCMFrameCount/divisor, data);

    rate = wav.sampleRate;
    channels = wav.channels;

    return AL_NO_ERROR;
}

loaderError p_loadMp3(sds name) {
    drmp3 mp3;

    if (!drmp3_init_file(&mp3, name, NULL)) {
        return AL_CANT_LOAD_FILE;
    }

    int count = 0;

    length = (drmp3_get_pcm_frame_count(&mp3) * mp3.channels * sizeof(float));

    numFrames = drmp3_get_pcm_frame_count(&mp3);

    do {
        count++;
        divisor++;
        data = malloc(length/divisor);
        if (count == 64) {
            return AL_CANT_LOAD_FILE;
        }
    }
    while (data == NULL);

    drmp3_read_pcm_frames_f32(&mp3, drmp3_get_pcm_frame_count(&mp3)/divisor, data);

    rate = mp3.sampleRate;
    channels = mp3.channels;

    return AL_NO_ERROR;
}

loaderError loader_loadFile(sds name) {
    sds extension = sdsempty();
    extension = sdscpy(extension,name);
    sdsrange(extension, -4, -1);

    sds wav_ext = sdsnew(".wav");
    sds flac_ext = sdsnew("flac");
    sds mp3_ext = sdsnew(".mp3");

    loaderError err = AL_NO_ERROR;

    if (sdscmp(extension, wav_ext) == 0) {
        cur_filetype = AT_WAV;
        err = p_loadWav(name);
    }
    else if (sdscmp(extension, flac_ext) == 0) {
        cur_filetype = AT_FLAC;
        err = p_loadFlac(name);
    }
    else if (sdscmp(extension, mp3_ext) == 0) {
        cur_filetype = AT_MP3;
        err = p_loadMp3(name);
    }
    else {
        err = AL_CANT_LOAD_FILE;
    }

    sdsfree(wav_ext);
    sdsfree(flac_ext);
    sdsfree(mp3_ext);
    sdsfree(extension);

    return err;
}

loaderError loader_seek(int offset, int direction) {
    if (cur_chunk + offset > numFrames || cur_chunk - offset < 0 || offset > numFrames) {
        return AL_COULDNT_SEEK;
    }
    switch (direction) {
        case 0:
            cur_chunk = offset;
            break;
        case 1:
            cur_chunk += offset;
            break;
        case -1:
            cur_chunk -= offset;
            break;
        default:
            break;
    }
    return AL_NO_ERROR;
}

loaderError loader_getChunk(int wanted_length, AudioChunk *chunk) {
    if (cur_chunk + wanted_length > numFrames) {
        chunk->length = ((cur_chunk + wanted_length) - numFrames);
        return AL_CANT_GET_CHUNK;
    }
    else {
        chunk->length = wanted_length;
    }
    chunk->buffer = &data[cur_chunk];
    return AL_NO_ERROR;
}

audioType loader_getSupportedFormat(int index) {
    audioType supported[] = {AT_WAV,AT_MP3,AT_FLAC};
    if (index > 2) {
        return AT_NONE;
    }
    else {
        return supported[index];
    }
}

loaderError loader_freeFile() {
    free(data);
    data = NULL;
    length = 0;
    divisor = 0;
    return AL_NO_ERROR;
}

int loader_getRate() {
    return rate;
}

int loader_getChannels() {
    return channels;
}

void loader_quit() {
    free(data);
}

