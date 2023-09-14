#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;

    while (std::getline(cpuinfo, line)) {
        if (line.find("model name") != std::string::npos) {
            //Extract and print the processor name
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                std::string processorName = line.substr(pos + 2); // Skip ": "
                std::cout << "Processor Name: " << processorName << std::endl;
                break;
            }
        }
    }

    cpuinfo.close();
    return 0;
}
