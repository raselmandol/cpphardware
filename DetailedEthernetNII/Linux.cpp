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
/*
_________MANDOL_0101_RASEL___
_________MANDOL_0101_RASEL___
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_________MANDOL_0101_RASEL___
_________MANDOL_0101_RASEL___

_____010101_____________________
_0101010101010__________________
010101010101010_________________
01010101010101011_______________
01010101010101010_______________
01010101010101010101010101______
01010101010101010101010101010___
0101010100101010101010101010101_
01010101010101010101010101010101
010101010101010101010101010__01_
01010101010101010100101010101___
01010100101010010101010101______
01010101010101010101010_________
1010101010101010101_____________
01010101010101__________________
101010101_______________________
010101__________________________
10______________________________
*/
