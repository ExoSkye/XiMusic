/** @file */

#pragma once

#include <audioPlayer.h>
#include <sds.h>

typedef enum audioType {
    AT_NONE,
    AT_WAV,
    AT_MP3,
    AT_FLAC,
    AT_OGG,
    AT_OPUS,
    AT_MOD,
    AT_MID,
    AT_LEN
} audioType;

typedef enum loaderError {
    AL_NO_ERROR,
    AL_FILE_NOT_FOUND,
    AL_CANT_LOAD_FILE,
    AL_FILE_GONE,
    AL_COULDNT_SEEK
} loaderError;

/**
 * Loads a file and returns.
 * On a low memory system this may also just set the filename in the loader implementation so the file may be streamed.
 * @param name filename of the file to load
 * @return An loaderError value.
 */
loaderError loader_loadFile(sds name);

/**
 * Seek to another chunk in the file
 * returns AP_CANT_SEEK if seek is not possible (goes before the first chink or after the last chunk).
 * @param offset the offset (used in conjunction with direction to describe how and where to seek to).
 * @param direction the direction (valid values are 0, 1 and -1, meaning from the start, forward and backwards respectively).
 * @return An loaderError value.
 */
loaderError loader_seek(int offset, int direction);

/**
 * Gets the current chunk.
 * @param length The length of the chunk that this function should recieve.
 * @return An loaderError value.
 */
AudioChunk loader_getChunk(int length);

/**
 * Gets the nth supported format.
 * @param index The index.
 * @return The audioType (AT_NONE if there are no more).
 */
audioType loader_getSupportedFormat(int index);

/**
 * Frees the current file.
 * @return An loaderError value.
 */
loaderError loader_freeFile();

/**
 * Quits the loader.
 */
void loader_quit();
