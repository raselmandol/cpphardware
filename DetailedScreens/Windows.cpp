//using displayDevice
#include <iostream>
#include <windows.h>

int main() {
    int numScreens = GetSystemMetrics(SM_CMONITORS);

    for (int i = 0; i < numScreens; ++i) {
        DISPLAY_DEVICE displayDevice;
        displayDevice.cb = sizeof(DISPLAY_DEVICE);
        if (EnumDisplayDevices(nullptr, i, &displayDevice, 0)) {
            std::cout << "Screen " << i << ":\n";
            std::cout << "Device Name: " << displayDevice.DeviceName << std::endl;
            std::cout << "Device String: " << displayDevice.DeviceString << std::endl;
            std::cout << std::endl;
        }
    }

    return 0;
}
