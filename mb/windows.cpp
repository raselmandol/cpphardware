#include <iostream>
#include <Windows.h>

int main() {
    char buffer[256];
    DWORD bufferSize = sizeof(buffer);

    if (GetComputerNameEx(ComputerNamePhysicalDnsHostname, buffer, &bufferSize)) {
        std::cout << "Motherboard Name: " << buffer << std::endl;
    } else {
        std::cerr << "Failed to retrieve motherboard name" << std::endl;
    }

    return 0;
}
