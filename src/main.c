#include "audioPlayer.h"
#include "audioEffect.h"
#include "audioLoader.h"

/**
 * Main function
 * Currently only plays a test file (or should do).
 */


int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please supply a filename");
        return -1;
    }

    sds name = sdsnew(argv[1]);

    audioType supported = AT_NONE;
    int index = 0;

    do {
        supported = loader_getSupportedFormat(index);

        switch (supported) {
            case AT_WAV:
                printf("WAV is supported.\n");
                break;
            case AT_FLAC:
                printf("FLAC is supported.\n");
                break;
            case AT_MP3:
                printf("MP3 is supported.\n");
                break;
            default:
                if (supported != AT_NONE) {
                    printf("Format %i is supported.\n", supported);
                }
                break;
        }

        index++;
    }
    while (supported != AT_NONE);

    loader_loadFile(name);

    int rate = loader_getRate();
    int channels = loader_getChannels();

    player_init(rate, channels);

    effect_init();

    audioEffectParams params;
    params.volume.volume = 0.1f;
    audioEffect effect = {AET_VOLUME, params};
    effect_addEffect(effect);

    int optimumChuckSize = effect_getOptimumChunkSize();
    AudioChunk chunk;

    do {
        loader_getChunk(optimumChuckSize, &chunk);
        effect_runEffects(&chunk);
        player_playChunk(chunk);
    }
    while (loader_seek(optimumChuckSize,1) != AL_COULDNT_SEEK);

    loader_freeFile();
    loader_quit();
    effect_quit();
    player_quit();

    sdsfree(name);
}