#include <iostream>

int main() {
    SYSTEM_INFO systemInfo;
    GetSystemInfo(&systemInfo);

    std::cout << "Processor Architecture: ";
    switch (systemInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:
            std::cout << "x64 (AMD or Intel)";
            break;
        case PROCESSOR_ARCHITECTURE_ARM:
            std::cout << "ARM";
            break;
        case PROCESSOR_ARCHITECTURE_IA64:
            std::cout << "Intel Itanium-based";
            break;
        case PROCESSOR_ARCHITECTURE_INTEL:
            std::cout << "x86";
            break;
        default:
            std::cout << "Unknown";
            break;
    }
    std::cout << std::endl;

    std::cout << "Number of Processors: " << systemInfo.dwNumberOfProcessors << std::endl;
    std::cout << "Page Size: " << systemInfo.dwPageSize << " bytes" << std::endl;
    std::cout << "Processor Type: " << systemInfo.dwProcessorType << std::endl;

    return 0;
}
