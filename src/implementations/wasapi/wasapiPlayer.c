#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#include <audioclient.h>
#include <audioPlayer.h>
#include <mmdeviceapi.h>
#include <audioResampler.h>
#include <audioEffect.h>

#define WIN32_CALL(error) if (FAILED(error)) return AP_INIT_FAILED

#define REFTIMES_PER_SEC  10000000
#define REFTIMES_PER_MILLISEC  10000

audioPlayerError player_init(int rate, int channels) {
    IMMDeviceEnumerator* enumerator = NULL;
    IMMDevice* device = NULL;

    WIN32_CALL(CoCreateInstance(
            &CLSID_MMDeviceEnumerator, NULL,
            CLSCTX_ALL, &IID_IMMDeviceEnumerator,
            (void**)&enumerator
    ));

    WIN32_CALL(enumerator->lpVtbl->GetDefaultAudioEndpoint(enumerator, eRender, eConsole, &device));

    IAudioClient* client;

    WIN32_CALL(device->lpVtbl->Activate(device, &IID_IAudioClient, CLSCTX_ALL, NULL, (void**)&client));

    WAVEFORMATEX* wave_format;

    WIN32_CALL(client->lpVtbl->GetMixFormat(client,&wave_format));

    //WIN32_CALL(client->lpVtbl->Initialize(client,AUDCLNT_SHAREMODE_SHARED,0,))

    return AP_NO_ERROR;
}

audioPlayerError player_playChunk(AudioChunk chunk) {

}

audioPlayerError player_quit() {

}