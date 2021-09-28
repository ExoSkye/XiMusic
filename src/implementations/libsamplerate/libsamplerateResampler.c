#include <samplerate.h>
#include <audioResampler.h>
#include <audioPlayer.h>
#include <stdbool.h>
#include <malloc.h>

SRC_STATE *state;

void resampler_init(int channels) {
    state = src_new(SRC_SINC_FASTEST, channels, NULL);
}

bool resampleChunk(AudioChunk *chunk, int current_freq, int wanted_freq) {
    float current_length = (float) chunk->length / (float) current_freq;

    float *dest = malloc(current_length * wanted_freq * sizeof(float));

    SRC_DATA data;
    data.data_in = chunk->buffer;
    data.data_out = dest;
    data.input_frames = chunk->length;
    data.output_frames = current_length * wanted_freq;
    data.src_ratio = wanted_freq / current_freq;
    data.end_of_input = 0;

    src_process(state, &data);

    free(chunk->buffer);
    chunk->buffer = dest;
    chunk->length = current_length * wanted_freq;
}

void resampler_free() {
    src_delete(state);
}