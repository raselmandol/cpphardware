#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    //meminfo
    std::ifstream meminfo("/proc/meminfo");
    std::string line;
    while (std::getline(meminfo, line)) {
        std::cout << line << std::endl;
    }
    return 0;
}
