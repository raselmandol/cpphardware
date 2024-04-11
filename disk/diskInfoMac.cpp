#include <iostream>
#include <string>
//use --> sys/types.h
#include <sys/types.h>
#include <sys/sysctl.h>
int main() {
    int mib[2];
    size_t len;
    mib[0] = CTL_HW;
    mib[1] = HW_MEMSIZE;
    len = sizeof(uint64_t);
    
    uint64_t memSize;
    if (sysctl(mib, 2, &memSize, &len, nullptr, 0) == 0) {
        std::cout << "Total Memory: " << memSize / (1024 * 1024 * 1024) << " GB" << std::endl;
    } else {
        std::cerr << "Failed to retrieve memory information." << std::endl;
        return 1;
    }
    return 0;
}
