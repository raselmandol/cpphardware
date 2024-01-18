#include <iostream>
#include <cpuid.h>

int main() {
    unsigned int regs[4];

    //getting vendor ID
    __cpuid(0, regs[0], regs[1], regs[2], regs[3]);
    std::cout << "Vendor ID: " << std::hex
              << regs[1] << regs[3] << regs[2] << std::dec << std::endl;

    //getting CPU information
    __cpuid(1, regs[0], regs[1], regs[2], regs[3]);
    //printing cpuInfo
    std::cout << "CPU Family: " << ((regs[0] >> 8) & 0xF) << std::endl;
    std::cout << "CPU Model: " << ((regs[0] >> 4) & 0xF) << std::endl;

    return 0;
}
