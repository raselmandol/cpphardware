#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main() {
    std::string line;
    std::ifstream iwconfig("/sbin/iwconfig");

    if (!iwconfig) {
        std::cerr << "Failed to open iwconfig." << std::endl;
        return 1;
    }
    while (std::getline(iwconfig, line)) {
        std::cout << line << std::endl;
    }

    iwconfig.close();
    return 0;
}
