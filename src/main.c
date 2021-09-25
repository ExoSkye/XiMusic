#include "audioPlayer.h"
#include "audioEffect.h"

/**
 * Main function
 * Currently only plays a test file (or should do).
 */


int main() {
    player_init();
    player_loadFile(sdsnew("test.wav"));

    effect_init();

    audioEffectParams params;
    params.volume.volume = 0.7f;
    audioEffect effect = {AET_VOLUME, params};
    effect_addEffect(effect);

    int optimumChuckSize = effect_getOptimumChunkSize();
    AudioChunk chunk;

    do {
        chunk = player_getChunk(optimumChuckSize);
        effect_runEffects(&chunk);
        player_playChunk(chunk);
    }
    while (player_seek(optimumChuckSize,1) != AP_CANT_SEEK);

    effect_quit();
    player_freeFile();
    player_quit();
}