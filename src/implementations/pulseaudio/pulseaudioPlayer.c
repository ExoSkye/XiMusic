#include <audioPlayer.h>
#include <pulse/simple.h>

pa_simple* sock;
pa_sample_spec sample_spec;

audioPlayerError player_init() {
    sample_spec.format = PA_SAMPLE_FLOAT32LE;
    sample_spec.channels = 2;
    sample_spec.rate = 192000;

    sock = pa_simple_new(
            NULL,
            "XiMusic",
            PA_STREAM_PLAYBACK,
            NULL,
            "Music",
            &sample_spec,
            NULL,NULL,NULL);

    return sock == NULL ? AP_INIT_FAILED : AP_NO_ERROR;
}

audioPlayerError player_playChunk(AudioChunk chunk) {
    return AP_NO_ERROR;
}

audioPlayerError player_quit() {
    pa_simple_free(sock);
    return AP_NO_ERROR;
}