#include <CoreAudio/CoreAudio.h>
#include <iostream>

int main() {
    AudioObjectPropertyAddress propAddress;
    propAddress.mSelector = kAudioHardwarePropertyDevices;
    propAddress.mScope = kAudioObjectPropertyScopeGlobal;
    propAddress.mElement = kAudioObjectPropertyElementMaster;

    AudioObjectID* deviceIDs = nullptr;
    UInt32 dataSize = 0;
    OSStatus status = AudioObjectGetPropertyDataSize(kAudioObjectSystemObject, &propAddress, 0, nullptr, &dataSize);

    if (status == noErr && dataSize > 0) {
        deviceIDs = new AudioObjectID[dataSize / sizeof(AudioObjectID)];
        status = AudioObjectGetPropertyData(kAudioObjectSystemObject, &propAddress, 0, nullptr, &dataSize, deviceIDs);
    }

    if (status == noErr) {
        std::cout << "Number of Speakers: " << (dataSize / sizeof(AudioObjectID)) << std::endl;

        for (UInt32 i = 0; i < (dataSize / sizeof(AudioObjectID)); i++) {
            AudioObjectID deviceID = deviceIDs[i];

            CFStringRef deviceName;
            dataSize = sizeof(CFStringRef);
            propAddress.mSelector = kAudioDevicePropertyDeviceName;
            status = AudioObjectGetPropertyData(deviceID, &propAddress, 0, nullptr, &dataSize, &deviceName);

            if (status == noErr) {
                char name[256];
                CFStringGetCString(deviceName, name, sizeof(name), kCFStringEncodingUTF8);
                std::cout << "Speaker " << i + 1 << " Name: " << name << std::endl;
            }
        }
    }

    if (deviceIDs) {
        delete[] deviceIDs;
    }

    return 0;
}
