#include <audioEffect.h>
#include <malloc.h>

audioEffect* effects = NULL;
size_t effects_length = 0;

audioEffectErrors effect_init() {
    return AE_NO_ERROR;
}

int effect_getOptimumChunkSize() {
    return 256;
}

audioEffectErrors effect_addEffect(audioEffect effect) {
    if (effects_length == 0) {
        effects = calloc(sizeof(audioEffect),1);
        effects_length = 1;
    }
    else {
        effects_length++;
        effects = realloc(effects, effects_length);
    }
    effects[effects_length - 1] = effect;
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
    for (int i = 0; i < effects_length; i++) {
        switch (effects[i].type) {
            case AET_VOLUME:
            {
                for (int j = 0; j < chunk->length; j++) {
                    chunk->buffer[j] *= effects[i].params.volume.volume;
                }
                break;
            }
            default:
                break;
        }
    }
    return AE_NO_ERROR;
}

audioEffectErrors effect_runEffectByIndex(AudioChunk* chunk, int index) {
    return AE_NO_ERROR;
}

audioEffectErrors effect_runEffectByPointer(AudioChunk* chunk, audioEffect* effect) {
    return AE_NO_ERROR;
}

audioEffectErrors effect_quit() {
    if (effects != NULL) {
	    free(effects);
    }
    return AE_NO_ERROR;
}