#include <audioPlayer.h>
#include <pulse/simple.h>
#include <unistd.h>

pa_simple *sock;
pa_sample_spec sample_spec;

audioPlayerError player_init(int rate, int channels) {
    sample_spec.format = PA_SAMPLE_FLOAT32LE;
    sample_spec.channels = channels;
    sample_spec.rate = rate;

    sock = pa_simple_new(
            NULL,
            "ΞMusic",
            PA_STREAM_PLAYBACK,
            NULL,
            "ΞMusic",
            &sample_spec,
            NULL, NULL, NULL);

    return sock == NULL ? AP_INIT_FAILED : AP_NO_ERROR;
}

audioPlayerError player_playChunk(AudioChunk chunk) {
    if (pa_simple_write(sock, chunk.buffer, chunk.length * sizeof(float), NULL) < 0) {
        return AP_CANT_PLAY;
    }
    return AP_NO_ERROR;
}

audioPlayerError player_quit() {
    pa_simple_drain(sock, NULL);
    pa_simple_free(sock);
    return AP_NO_ERROR;
}