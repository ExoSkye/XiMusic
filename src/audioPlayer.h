/** @file */

#pragma once

#include <sds.h>
#include <stdio.h>

/**
 * Describes possible errors that can occur in the audio player.
 */
typedef enum audioPlayerError {
    AP_NO_ERROR,
    AP_INIT_FAILED,
    AP_CANT_INIT_AUDIO,
    AP_CANT_PLAY,
    AP_INVALID_PLATFORM,
    AP_LEN
} audioPlayerError;

/**
 * Struct which is used to hold a chunk of audio - used for communication with the audio effect engine.
 */
typedef struct AudioChunk {
    /// Pointer to the start of the chunk in memory.
    float* buffer;
    /// Length of the buffer.
    uint32_t length; 
} AudioChunk;

/**
 * Initializes the player.
 * @return An audioPlayerError value.
 */
audioPlayerError player_init(int rate, int channels);

/**
 * Plays the provided chunk.
 * Used after the effects have been applied.
 * @param chunk Chunk to play.
 * @return An audioPlayerError value.
 */
audioPlayerError player_playChunk(AudioChunk chunk);



/**
 * Quits the player.
 * @return An audioPlayerError value.
 */
audioPlayerError player_quit();
