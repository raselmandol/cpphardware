#include <iostream>
#include <windows.h>
#include <wlanapi.h>

#pragma comment(lib, "wlanapi.lib")

int main() {
    HANDLE clientHandle;
    DWORD negotiatedVersion;
    if (WlanOpenHandle(2, nullptr, &negotiatedVersion, &clientHandle) != ERROR_SUCCESS) {
        std::cerr << "Failed to open WLAN handle." << std::endl;
        return 1;
    }

    WLAN_INTERFACE_INFO_LIST* ifList = nullptr;
    if (WlanEnumInterfaces(clientHandle, nullptr, &ifList) != ERROR_SUCCESS) {
        std::cerr << "Failed to enumerate WLAN interfaces." << std::endl;
        WlanCloseHandle(clientHandle, nullptr);
        return 1;
    }

    for (DWORD i = 0; i < ifList->dwNumberOfItems; i++) {
        WLAN_INTERFACE_INFO& ifInfo = ifList->InterfaceInfo[i];

        std::wcout << L"Interface Name: " << ifInfo.strInterfaceDescription << std::endl;
        std::wcout << L"Interface GUID: " << ifInfo.InterfaceGuid << std::endl;
        std::wcout << std::endl;
    }

    WlanFreeMemory(ifList);
    WlanCloseHandle(clientHandle, nullptr);

    return 0;
}
