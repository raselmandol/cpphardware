#include <iostream>
void GetCpuInfo(unsigned int function, unsigned int subFunction, unsigned int cpuInfo[4]) {
    asm volatile (
        "cpuid"
        : "=a" (cpuInfo[0]), "=b" (cpuInfo[1]), "=c" (cpuInfo[2]), "=d" (cpuInfo[3])
        : "a" (function), "c" (subFunction)
    );
}

int main() {
    unsigned int cpuInfo[4] = {0};
    GetCpuInfo(0x00000000, 0x00000000, cpuInfo);

    unsigned int maxFunction = cpuInfo[0]; // Maximum supported CPUID function
    char vendorString[13];
    *reinterpret_cast<int*>(vendorString) = cpuInfo[1];
    *reinterpret_cast<int*>(vendorString + 4) = cpuInfo[3];
    *reinterpret_cast<int*>(vendorString + 8) = cpuInfo[2];
    vendorString[12] = '\0';

    std::cout << "Vendor ID: " << vendorString << std::endl;
    std::cout << "Max CPUID Function: " << maxFunction << std::endl;
    if (maxFunction >= 0x80000000) {
        GetCpuInfo(0x80000000, 0x00000000, cpuInfo);

        unsigned int maxExtendedFunction = cpuInfo[0];
        std::cout << "Max Extended CPUID Function: " << maxExtendedFunction << std::endl;
    }

    return 0;
}
