#include <Windows.h>
#include <SetupAPI.h>
#include <iostream>

int main() {
    HDEVINFO hDevInfo;
    SP_DEVINFO_DATA devInfoData;
    DWORD index = 0;

    hDevInfo = SetupDiGetClassDevs(&GUID_DEVINTERFACE_USB_DEVICE, 0, 0, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);
    if (hDevInfo == INVALID_HANDLE_VALUE) {
        std::cerr << "SetupDiGetClassDevs failed." << std::endl;
        return 1;
    }

    devInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
    while (SetupDiEnumDeviceInfo(hDevInfo, index, &devInfoData)) {
        char buffer[256];
        if (SetupDiGetDeviceRegistryProperty(hDevInfo, &devInfoData, SPDRP_DEVICEDESC, 0, (BYTE*)buffer, sizeof(buffer), 0)) {
            std::cout << "USB Device: " << buffer << std::endl;
        }
        index++;
    }

    SetupDiDestroyDeviceInfoList(hDevInfo);
    return 0;
}
