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
/*
_________MANDOL_0101_RASEL___
_________MANDOL_0101_RASEL___
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_________MANDOL_0101_RASEL___
_________MANDOL_0101_RASEL___

_____010101_____________________
_0101010101010__________________
010101010101010_________________
01010101010101011_______________
01010101010101010_______________
01010101010101010101010101______
01010101010101010101010101010___
0101010100101010101010101010101_
01010101010101010101010101010101
010101010101010101010101010__01_
01010101010101010100101010101___
01010100101010010101010101______
01010101010101010101010_________
1010101010101010101_____________
01010101010101__________________
101010101_______________________
010101__________________________
10______________________________
*/
