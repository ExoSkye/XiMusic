#include "audioPlayer.h"
#include "audioEffect.h"
#include "audioLoader.h"

/**
 * Main function
 * Currently only plays a test file (or should do).
 */


int main(int argc, char** argv) {
    sds name = sdsnew("test.wav");

    player_init();

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

    effect_init();

    audioEffectParams params;
    params.volume.volume = 0.7f;
    audioEffect effect = {AET_VOLUME, params};
    effect_addEffect(effect);

    int optimumChuckSize = effect_getOptimumChunkSize();
    AudioChunk chunk;

    do {
        chunk = loader_getChunk(optimumChuckSize);
        effect_runEffects(&chunk);
        player_playChunk(chunk);
    }
    while (loader_seek(1,1) != AL_COULDNT_SEEK);

    loader_freeFile();
    loader_quit();
    effect_quit();
    player_quit();

    sdsfree(name);
}