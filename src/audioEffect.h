/** @file */

#pragma once

#include "audioPlayer.h"

/// The current audio effects that are supported.
typedef enum audioEffectTypes {
    /// None value, used for when an audioEffect doesn't exist.
    AET_NONE,
    /// Volume value
    AET_VOLUME,
    /// Bass value
    AET_BASS,
    /// Treble value
    AET_TREBLE,
    /// 31 band equalizer (can be simplified by ui)
    AET_EQUALIZER
} audioEffectTypes;

/// The errors that an audioEffect operation can return.
typedef enum audioEffectErrors {
    /// No error - the operation completed successfully.
    AE_NO_ERROR,
    /// Can't run - not enough system resources etc.
    AE_CANT_RUN,
    /// Bad chunk - chunk wasn't valid.
    AE_BAD_CHUNK,
    /// Wrong platform - the effects can't work on this platform.
    AE_WRONG_PLATFORM
} audioEffectErrors;

/// The parameters for the volume effect.
typedef struct effectVolume {
    float volume; /// Value for the volume.
} effectVolume;

/// The parameters for the bass effect.
typedef struct effectBass {
    float bass_volume; /// Volume for the bass.
} effectBass;

/// The parameters for the treble effect.
typedef struct effectTreble {
    float treble_volume; /// Volume for the treble.
} effectTreble;

/// The parameters for the equalizer effect.
typedef struct effectEqualizer {
    float faders[31]; /// Faders used by the equalizer.
} effectEqualizer;

/// The union of the parameters for the effect.
typedef union audioEffectParams {
    effectVolume volume; /// Parameters for the volume effect.
    effectBass bass; /// Parameters for the bass effect.
    effectTreble treble; /// Parameters for the treble effect.
    effectEqualizer equalizer; /// Parameters for the equalizer effect.
} audioEffectParams;

/// The struct that contains an audio effect and it's parameters.
typedef struct audioEffect {
    audioEffectTypes type; /// Type of the audio effect.
    audioEffectParams params; /// The parameters for that audio effect.
} audioEffect;

/**
 * Initializes the audio effect engine.
 * @return An audioEffectErrors value.
 */
audioEffectErrors effect_init();

/**
 * Add the effect to the list.
 * @param effect
 * @return An audioEffectErrors value.
 */
audioEffectErrors effect_addEffect(audioEffect effect);

/**
 * Gets the pointer to the underlying value returned by getEffect.
 * Doesn't copy the value, just returns the value.
 * @param index The index of the effect.
 * @return Pointer to the effect. (if type == AET_NONE then that value doesn't exist)
 */
audioEffect* effect_getEffectPTR(int index);

/**
 * Gets a copy of the effect at index index.
 * @param index The index of the effect.
 * @return Copy of the effect. (if type == AET_NONE then that value doesn't exist)
 */
audioEffect effect_getEffect(int index);

/**
 * Deletes the effect at the specified index from the effect list.
 * @param index The index of the effect to delete.
 * @return An audioEffectErrors value.
 */
audioEffectErrors effect_deleteEffectByIndex(int index);

/**
 * Deletes the effect specified by the pointer from the effect list.
 * @param effect Pointer to the effect to delete.
 * @return An audioEffectErrors value.
 */
audioEffectErrors effect_deleteEffectByPointer(audioEffect* effect);

/**
 * Run all effects on a chunk.
 * @param chunk Pointer to the chunk to apply the effects on.
 * @return An audioEffectErrors value.
 */
audioEffectErrors effect_runEffects(AudioChunk* chunk);

/**
 * Run the effect (specified by the index) on a chunk.
 * @param chunk Pointer to the chunk to apply the effects on.
 * @param index Index of the effect to apply.
 * @return An audioEffectErrors value.
 */
audioEffectErrors effect_runEffectByIndex(AudioChunk* chunk, int index);

/**
 * Run the effect (specified by the pointer) on a chunk.
 * @param chunk Pointer to the chunk to apply the effects on.
 * @param effect Pointer to the effect to apply.
 * @return An audioEffectErrors value.
 */
audioEffectErrors effect_runEffectByPointer(AudioChunk* chunk, audioEffect* effect);

/**
 * Quits the effect engine.
 * @return An audioEffectErrors value.
 */
audioEffectErrors effect_quit();