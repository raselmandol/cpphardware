#include <iostream>
#include <CoreAudio/CoreAudio.h>

int main() {
    UInt32 propertySize;
    AudioObjectPropertyAddress propertyAddress;
    AudioObjectID deviceID;
    OSStatus status;
    propertyAddress.mSelector = kAudioHardwarePropertyDevices;
    propertyAddress.mScope = kAudioObjectPropertyScopeInput;
    propertyAddress.mElement = kAudioObjectPropertyElementMaster;

    status = AudioObjectGetPropertyDataSize(kAudioObjectSystemObject, &propertyAddress, 0, NULL, &propertySize);
    if (status == noErr) {
        AudioDeviceID *deviceIDs = new AudioDeviceID[propertySize / sizeof(AudioDeviceID)];

        status = AudioObjectGetPropertyData(kAudioObjectSystemObject, &propertyAddress, 0, NULL, &propertySize, deviceIDs);
        if (status == noErr) {
            for (UInt32 i = 0; i < propertySize / sizeof(AudioDeviceID); ++i) {
                deviceID = deviceIDs[i];
                // Retrieve and print device information as needed.
            }
        }

        delete[] deviceIDs;
    }

    return 0;
}
