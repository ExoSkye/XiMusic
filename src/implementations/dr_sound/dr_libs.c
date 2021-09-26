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
uint32_t divisor = 0;
uint32_t cur_chunk = 0;
audioType cur_filetype = AT_NONE;

loaderError p_loadFlac(sds name) {
    drflac* flac = drflac_open_file("my_song.flac", NULL);
    if (flac == NULL) {
        return AL_CANT_LOAD_FILE;
    }

    int count = 0;

    length = ((size_t)flac->totalPCMFrameCount * flac->channels * sizeof(float));

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

    return AL_NO_ERROR;
}

loaderError p_loadWav(sds name) {
    drwav wav;
    if (!drwav_init_file(&wav, name, NULL)) {
        return AL_CANT_LOAD_FILE;
    }

    int count = 0;

    length = ((size_t)wav.totalPCMFrameCount * wav.channels * sizeof(float));

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

    return AL_NO_ERROR;
}

loaderError p_loadMp3(sds name) {
    drmp3 mp3;

    if (!drmp3_init_file(&mp3, name, NULL)) {
        return AL_CANT_LOAD_FILE;
    }

    int count = 0;

    length = (drmp3_get_pcm_frame_count(&mp3) * mp3.channels * sizeof(float));

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
    if (cur_chunk + offset > length || cur_chunk - offset < 0 || offset > length) {
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

AudioChunk loader_getChunk(int length) {

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

void loader_quit() {
    free(data);
}