#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;
    while (std::getline(cpuinfo, line)) {
        std::cout << line << std::endl;
    }
    return 0;
}
