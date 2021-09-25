#include <audioPlayer.h>
#include <stdio.h>
#include <SDL.h>

audioPlayerError player_init() {
    if (SDL_Init(SDL_INIT_AUDIO) != 0) {
        printf("Couldn't init SDL_Audio, error: %s", SDL_GetError());
        return AP_INIT_FAILED;
    }
    return AP_NO_ERROR;
}

audioPlayerError player_loadFile(sds name) {
    return AP_NO_ERROR;
}

audioPlayerError player_seek(int offset, int direction) {
    return AP_CANT_SEEK;
}

AudioChunk player_getChunk(int length) {
    AudioChunk chunk;
    chunk.buffer = NULL;
    chunk.length = 0;
    return chunk;
}

audioPlayerError player_playChunk(AudioChunk chunk) {
    return AP_NO_ERROR;
}

audioType player_getSupportedFormat(int index) {
    return AT_NONE;
}

audioPlayerError player_freeFile() {
    return AP_NO_ERROR;
}

audioPlayerError player_quit() {
    SDL_Quit();
    return AP_NO_ERROR;
}