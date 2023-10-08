#include <iostream>
#include <windows.h>

int main() {
    OSVERSIONINFOEX osvi;
    ZeroMemory(&osvi, sizeof(OSVERSIONINFOEX));
    osvi.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);

    if (GetVersionEx((OSVERSIONINFO*)&osvi)) {
        std::cout << "Windows Kernel Information:" << std::endl;
        std::cout << "Major Version: " << osvi.dwMajorVersion << std::endl;
        std::cout << "Minor Version: " << osvi.dwMinorVersion << std::endl;
        std::cout << "Build Number: " << osvi.dwBuildNumber << std::endl;
    } else {
        std::cerr << "Error getting Windows kernel information." << std::endl;
        return 1;
    }

    return 0;
}
