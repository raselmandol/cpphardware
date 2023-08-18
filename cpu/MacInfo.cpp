#include <iostream>
#include <string>
#include <sys/types.h>
#include <sys/sysctl.h>

int main() {
    int mib[2];
    size_t len;
    mib[0] = CTL_HW;
    mib[1] = HW_NCPU;
    len = sizeof(int);
    int numCores;
    if (sysctl(mib, 2, &numCores, &len, nullptr, 0) == 0) {
        std::cout << "Number of Cores: " << numCores << std::endl;
    } else {
        std::cerr << "Failed to retrieve CPU core information." << std::endl;
        return 1;
    }
    mib[1] = HW_CPU_FREQ;
    len = sizeof(uint64_t);
    uint64_t cpuFreq;
    if (sysctl(mib, 2, &cpuFreq, &len, nullptr, 0) == 0) {
        std::cout << "CPU Frequency: " << cpuFreq / 1000000 << " MHz" << std::endl;
    } else {
        std::cerr << "Failed to retrieve CPU frequency information." << std::endl;
        return 1;
    }
    
    return 0;
}
