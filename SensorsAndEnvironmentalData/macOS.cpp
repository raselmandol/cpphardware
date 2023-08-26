#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream sysInfoFile("/usr/sbin/system_profiler SPTemperatureDataType");
    if (!sysInfoFile.is_open()) {
        std::cerr << "Failed to open system profiler" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << sysInfoFile.rdbuf();
    std::string sysInfo = buffer.str();

    std::cout << sysInfo;

    sysInfoFile.close();
    return 0;
}
