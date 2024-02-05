//My time has come
//living the last moments

#include <iostream>
#include <Windows.h>

int main() {
    int numDevices = waveInGetNumDevs();
    std::cout << "Input Audio Devices:" << std::endl;
    for (int i = 0; i < numDevices; ++i) {
        WAVEINCAPS deviceInfo;
        if (waveInGetDevCaps(i, &deviceInfo, sizeof(deviceInfo)) == MMSYSERR_NOERROR) {
            std::cout << "Device " << i << ": " << deviceInfo.szPname << std::endl;
        }
    }
    std::cout << "Output Audio Devices:" << std::endl;
    numDevices = waveOutGetNumDevs();
    for (int i = 0; i < numDevices; ++i) {
        WAVEOUTCAPS deviceInfo;
        if (waveOutGetDevCaps(i, &deviceInfo, sizeof(deviceInfo)) == MMSYSERR_NOERROR) {
            //more infos here
            std::cout << "Device " << i << ": " << deviceInfo.szPname << std::endl;
        }
    }
    return 0;
}
