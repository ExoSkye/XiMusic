#include <audioEffect.h>

audioEffectErrors effect_init() {
    return AE_NO_ERROR;
}

int effect_getOptimumChunkSize() {
    return 0;
}

audioEffectErrors effect_addEffect(audioEffect effect) {
    return AE_NO_ERROR;
}

audioEffect* effect_getEffectPTR(int index) {
    return NULL;
}

audioEffect effect_getEffect(int index) {
    audioEffect effect;
    effect.type = AET_NONE;
    return effect;
}

audioEffectErrors effect_deleteEffectByIndex(int index) {
    return AE_NO_ERROR;
}

audioEffectErrors effect_deleteEffectByPointer(audioEffect* effect) {
    return AE_NO_ERROR;
}

audioEffectErrors effect_runEffects(AudioChunk* chunk) {
    return AE_CANT_RUN;
}

audioEffectErrors effect_runEffectByIndex(AudioChunk* chunk, int index) {
    return AE_CANT_RUN;
}

audioEffectErrors effect_runEffectByPointer(AudioChunk* chunk, audioEffect* effect) {
    return AE_CANT_RUN;
}

audioEffectErrors effect_quit() {
    return AE_NO_ERROR;
}