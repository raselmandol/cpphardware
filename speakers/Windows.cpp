#include <iostream>
#include <windows.h>

int main() {
    int numSpeakers = waveOutGetNumDevs();

    if (numSpeakers > 0) {
        std::cout << "Number of Speakers: " << numSpeakers << std::endl;

        for (int i = 0; i < numSpeakers; i++) {
            WAVEOUTCAPS waveOutCaps;
            if (waveOutGetDevCaps(i, &waveOutCaps, sizeof(WAVEOUTCAPS)) == MMSYSERR_NOERROR) {
                std::cout << "Speaker " << i + 1 << " Name: " << waveOutCaps.szPname << std::endl;
            }
        }
    } else {
        std::cout << "No speakers detected." << std::endl;
    }

    return 0;
}
