#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;

    while (std::getline(cpuinfo, line)) {
        if (line.find("model name") != std::string::npos) {
            size_t pos = line.find(":");
            if (pos != std::string::npos) {
                std::string modelName = line.substr(pos + 2); // Skip ": "
                std::cout << "Processor Model: " << modelName << std::endl;
                break;
            }
        }
    }
    cpuinfo.close();
    return 0;
}
