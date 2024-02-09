//using <sys/sysctl.h>, <sys/types.h>
#include <iostream>
#include <sys/types.h>
#include <sys/sysctl.h>

int main() {
    int mib[2];
    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    uint64_t ramSize;
    size_t length = sizeof(ramSize);

    if (sysctl(mib, 2, &ramSize, &length, nullptr, 0) == 0) {
        std::cout << "Total RAM: " << ramSize << " bytes" << std::endl;
    } else {
        std::cerr << "Failed to retrieve RAM information." << std::endl;
    }

    return 0;
}
