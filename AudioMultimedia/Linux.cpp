#include <iostream>
#include <alsa/asoundlib.h>

int main() {
    snd_pcm_t* pcm;
    if (snd_pcm_open(&pcm, "default", SND_PCM_STREAM_PLAYBACK, 0) < 0) {
        std::cerr << "Failed to open PCM device." << std::endl;
        return 1;
    }
    snd_pcm_prepare(pcm);
    snd_pcm_start(pcm);
    snd_pcm_drain(pcm);
    snd_pcm_close(pcm);

    return 0;
}
