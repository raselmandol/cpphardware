//using setupapi.lib
#include <iostream>
#include <windows.h>
#include <setupapi.h>
#include <devguid.h>
#include <usbioctl.h>

#pragma comment(lib, "setupapi.lib")

int main() {
    HDEVINFO hDeviceInfo;
    SP_DEVINFO_DATA deviceInfoData = { sizeof(SP_DEVINFO_DATA) };
    DWORD index = 0;

    hDeviceInfo = SetupDiGetClassDevs(&GUID_DEVCLASS_USB, 0, 0, DIGCF_PRESENT);

    if (hDeviceInfo == INVALID_HANDLE_VALUE) {
        std::cerr << "SetupDiGetClassDevs failed" << std::endl;
        return 1;
    }

    while (SetupDiEnumDeviceInfo(hDeviceInfo, index, &deviceInfoData)) {
        TCHAR deviceName[MAX_DEVICE_ID_LEN];
        if (CM_Get_Device_ID(deviceInfoData.DevInst, deviceName, MAX_PATH, 0)) {
            std::cerr << "CM_Get_Device_ID failed" << std::endl;
            continue;
        }
        std::wcout << "Device Name: " << deviceName << std::endl;

        ++index;
    }

    SetupDiDestroyDeviceInfoList(hDeviceInfo);

    return 0;
}
