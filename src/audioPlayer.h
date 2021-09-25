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
    AP_FILE_NOT_FOUND,
    AP_CANT_OPEN_FILE,
    AP_CANT_LOAD_FILE,
    AP_CANT_INIT_AUDIO,
    AP_CANT_PLAY_FILE,
    AP_CANT_SEEK,
    AP_INVALID_FORMAT,
    AP_INVALID_PLATFORM
} audioPlayerError;

/**
 * Describes possible audio formats that a player can play, see player_getSupportedFormat()
 */
typedef enum audioType {
    AT_NONE,
    AT_WAV,
    AT_MP3,
    AT_FLAC,
    AT_OGG
} audioType;

/**
 * Struct which is used to hold a chunk of audio - used for communication with the audio effect engine.
 */
typedef struct AudioChunk {
    float* buffer; /// Pointer to the start of the chunk in memory.
    uint32_t length; /// Length of the buffer.
} AudioChunk;

/**
 * Initializes the player.
 * @return An audioPlayerError value.
 */
audioPlayerError player_init();

/**
 * Loads a file and returns.
 * On a low memory system this may also just set the filename in the player implementation so the file may be streamed.
 * @param name filename of the file to load
 * @return An audioPlayerError value.
 */
audioPlayerError player_loadFile(sds name);

/**
 * Seek to another chunk in the file
 * returns AP_CANT_SEEK if seek is not possible (goes before the first chink or after the last chunk).
 * @param offset the offset (used in conjunction with direction to describe how and where to seek to).
 * @param direction the direction (valid values are 0, 1 and -1, meaning from the start, forward and backwards respectively).
 * @return An audioPlayerError value.
 */
audioPlayerError player_seek(int offset, int direction);

/**
 * Gets the current chunk.
 * @return An audioPlayerError value.
 */
AudioChunk player_getChunk();

/**
 * Plays the provided chunk.
 * Used after the effects have been applied.
 * @param chunk Chunk to play.
 * @return An audioPlayerError value.
 */
audioPlayerError player_playChunk(AudioChunk chunk);

/**
 * Gets the nth supported format.
 * @param index The index.
 * @return The audioType (AT_NONE if there are no more).
 */
audioType player_getSupportedFormat(int index);

/**
 * Frees the current file.
 * @return An audioPlayerError value.
 */
audioPlayerError player_freeFile();

/**
 * Quits the player.
 * @return An audioPlayerError value.
 */
audioPlayerError player_quit();
