//npos, meminfo
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream meminfo("/proc/meminfo");
    std::string line;

    while (std::getline(meminfo, line)) {
        if (line.find("MemTotal:") != std::string::npos) {
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                std::string ramSize = line.substr(pos + 2); // Skip ": "
                std::cout << "Total RAM: " << ramSize << std::endl;
                break;
            }
        }
    }

    meminfo.close();
    return 0;
}
