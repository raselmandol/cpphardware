//use EnumDisplayDevices
#include <iostream>
#include <windows.h>

int main() {
    DISPLAY_DEVICE displayDevice;
    displayDevice.cb = sizeof(DISPLAY_DEVICE);
    
    for (int i = 0; EnumDisplayDevices(NULL, i, &displayDevice, 0); i++) {
        if (displayDevice.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP) {
            std::cout << "Device Name: " << displayDevice.DeviceName << std::endl;
            std::cout << "Device String: " << displayDevice.DeviceString << std::endl;
            //Print other display details as needed
        }
    }

    return 0;
}
