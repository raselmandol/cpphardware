#include <iostream>
#include <Windows.h>

int main() {
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    if (GlobalMemoryStatusEx(&memInfo)) {
        std::cout << "Total Physical Memory: " << memInfo.ullTotalPhys / (1024 * 1024) << " MB" << std::endl;
        std::cout << "Available Physical Memory: " << memInfo.ullAvailPhys / (1024 * 1024) << " MB" << std::endl;
        std::cout << "Total Virtual Memory: " << memInfo.ullTotalVirtual / (1024 * 1024) << " MB" << std::endl;
        std::cout << "Available Virtual Memory: " << memInfo.ullAvailVirtual / (1024 * 1024) << " MB" << std::endl;
    } else {
        std::cerr << "Failed to retrieve memory information." << std::endl;
        return 1;
    }
    return 0;
}
