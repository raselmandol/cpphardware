#include <iostream>
#include <fstream>
#include <string>

int main() {
    //Get BIOS information on Linux can be challenging; often you may need to rely on third-party tools
    //For hardware information, you can use /proc filesystem
    std::ifstream cpuInfo("/proc/cpuinfo");
    std::string line;
    while (std::getline(cpuInfo, line)) {
        std::cout << line << std::endl;
    }

    return 0;
}
