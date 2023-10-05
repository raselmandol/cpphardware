#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct NetworkInterface {
    std::string name;
    std::string macAddress;
};

int main() {
    std::ifstream netInterfaces("/proc/net/dev");
    std::string line;
    std::vector<NetworkInterface> interfaces;

    while (std::getline(netInterfaces, line)) {
        if (line.find(':') != std::string::npos) {
            std::istringstream iss(line);
            std::string name, discard;
            iss >> name;
            iss.ignore(256, ':');
            iss >> discard;
            NetworkInterface interface;
            interface.name = name;
            interfaces.push_back(interface);
        }
    }

    for (const auto& iface : interfaces) {
        std::cout << "Interface Name: " << iface.name << std::endl;
    }

    return 0;
}
