#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream sysInfoFile("/usr/sbin/system_profiler SPHardwareDataType");
    if (!sysInfoFile.is_open()) {
        std::cerr << "Failed to open system profiler" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << sysInfoFile.rdbuf();
    std::string sysInfo = buffer.str();

    size_t boardNamePos = sysInfo.find("Board ID: ");
    if (boardNamePos != std::string::npos) {
        size_t end = sysInfo.find("\n", boardNamePos);
        if (end != std::string::npos) {
            std::string boardName = sysInfo.substr(boardNamePos + 10, end - boardNamePos - 10);
            std::cout << "Motherboard Name: " << boardName << std::endl;
        }
    }

    sysInfoFile.close();
    return 0;
}
