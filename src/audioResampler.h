/** @file */
#pragma once

#include <stdbool.h>
#include <audioPlayer.h>

/**
 * Initialize the resampler.
 */
void resampler_init(int channels);


/**
 * Run the resampler on a chunk.
 * @param chunk the chunk to resample.
 * @param current_freq The current frequency of that chunk.
 * @param wanted_freq The frequency that is required.
 * @return Whether the resampler was successful. (ie no errors)
 */
bool resampleChunk(AudioChunk* chunk, int current_freq, int wanted_freq);

/**
 * Free the resampler.
 */
void resampler_free();