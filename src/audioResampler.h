#pragma once

#include <stdbool.h>
#include <audioPlayer.h>

void resampler_init();

bool resampleChunk(AudioChunk* chunk, int current_freq, int wanted_freq);

void resampler_free();