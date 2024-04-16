#include <stdio.h>
//verify ObjectProprtyAdd, dataSize
//use deviceIds
#include <CoreAudio/CoreAudio.h>

int main() {
    AudioObjectPropertyAddress propertyAddress;
    propertyAddress.mSelector = kAudioHardwarePropertyDevices;
    propertyAddress.mScope = kAudioObjectPropertyScopeGlobal;
    propertyAddress.mElement = kAudioObjectPropertyElementMaster;

    UInt32 dataSize;
    AudioObjectGetPropertyDataSize(kAudioObjectSystemObject, &propertyAddress, 0, NULL, &dataSize);

    AudioObjectID* deviceIDs = (AudioObjectID*)malloc(dataSize);
    AudioObjectGetPropertyData(kAudioObjectSystemObject, &propertyAddress, 0, NULL, &dataSize, deviceIDs);

    for (UInt32 i = 0; i < dataSize / sizeof(AudioObjectID); i++) {
        propertyAddress.mSelector = kAudioDevicePropertyDeviceName;
        char deviceName[256];
        dataSize = sizeof(deviceName);

        if (AudioObjectGetPropertyData(deviceIDs[i], &propertyAddress, 0, NULL, &dataSize, deviceName) == noErr) {
            printf("Sound Card %d\n", i + 1);
            printf("Device Name: %s\n", deviceName);
            //Print other sound card details as needed
        }
    }

    free(deviceIDs);
    return 0;
}
