#include <iostream>
#include <Windows.h>
#include <tchar.h>
#include <atlstr.h>

int main() {
    //Get BIOS information
    TCHAR biosInfo[4096];
    GetFirmwareEnvironmentVariable(_T("SystemBiosDate"), _T("{00000000-0000-0000-0000-000000000000}"), biosInfo, sizeof(biosInfo));

    //hardware information using WMI
    std::system("wmic cpu get caption");
    std::system("wmic memorychip get capacity");
    //Add more WMI queries for additional hardware information as needed

    std::cout << "BIOS Information: " << CW2A(biosInfo) << std::endl;

    return 0;
}
