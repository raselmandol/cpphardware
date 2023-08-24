#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream netInterfaces("/proc/net/dev");
    if (!netInterfaces.is_open()) {
        std::cerr << "Failed to open /proc/net/dev" << std::endl;
        return 1;
    }

    std::string line;
    getline(netInterfaces, line); // Skip header line

    while (getline(netInterfaces, line)) {
        std::istringstream iss(line);
        std::string interfaceName;
        iss >> interfaceName;
        if (!interfaceName.empty()) {
            std::cout << "Interface Name: " << interfaceName << std::endl;
        }
    }

    netInterfaces.close();
    return 0;
}
