#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>

int main() {
    //init_deviceCount
    int deviceCount = waveOutGetNumDevs();
    
    for (int i = 0; i < deviceCount; i++) {
        WAVEOUTCAPS waveOutCaps;
        if (waveOutGetDevCaps(i, &waveOutCaps, sizeof(waveOutCaps)) == MMSYSERR_NOERROR) {
            printf("Sound Card %d\n", i + 1);
            printf("Device Name: %s\n", waveOutCaps.szPname);
            printf("Manufacturer ID: %d\n", waveOutCaps.wMid);
            printf("Product ID: %d\n", waveOutCaps.wPid);
            printf("Channels: %d\n", waveOutCaps.wChannels);
            printf("Support: 0x%X\n", waveOutCaps.dwSupport);
            //Print other sound card details as needed
        }
    }

    return 0;
}
