#include <iostream>
#include <sys/types.h>
#include <sys/sysctl.h>

int main() {
    char buffer[1024];
    size_t bufferSize = sizeof(buffer);
    
    if (sysctlbyname("machdep.cpu.brand_string", &buffer, &bufferSize, NULL, 0) == 0) {
        std::cout << "Processor Name: " << buffer << std::endl;
    } else {
        std::cerr << "Failed to retrieve processor information." << std::endl;
        return 1;
    }
    
    return 0;
}
