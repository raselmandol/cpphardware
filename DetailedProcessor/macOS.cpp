#include <iostream>
#include <sys/types.h>
#include <sys/sysctl.h>

int main() {
    char model[128];
    size_t len = sizeof(model);
    if (sysctlbyname("machdep.cpu.brand_string", model, &len, nullptr, 0) == 0) {
        std::cout << "Processor Model: " << model << std::endl;
    } else {
        std::cerr << "Failed to retrieve processor model." << std::endl;
    }
    return 0;
}
