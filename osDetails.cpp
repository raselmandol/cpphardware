#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <sys/utsname.h>

std::string GetLinuxDistro() {
    std::ifstream osRelease("/etc/os-release");
    std::string line;
    while (std::getline(osRelease, line)) {
        if (line.find("PRETTY_NAME=") != std::string::npos) {
            size_t start = line.find('"') + 1;
            size_t end = line.rfind('"');
            return line.substr(start, end - start);
        }
    }
    return "Unknown";
}

int main() {
    struct utsname system_info;
    if (uname(&system_info) == 0) {
        std::cout << "Kernel Name: " << system_info.sysname << std::endl;
        std::cout << "Node Name: " << system_info.nodename << std::endl;
        std::cout << "Kernel Release: " << system_info.release << std::endl;
        std::cout << "Kernel Version: " << system_info.version << std::endl;
        std::cout << "Machine Type: " << system_info.machine << std::endl;
    } else {
        std::cerr << "Error retrieving system information." << std::endl;
        return 1;
    }
    std::string distro = GetLinuxDistro();
    std::cout << "Linux Distribution: " << distro << std::endl;

    return 0;
}
