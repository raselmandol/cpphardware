#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::ifstream netInterfaces("/proc/net/dev");
    if (!netInterfaces.is_open()) {
        std::cerr << "Failed to open /proc/net/dev" << std::endl;
        return 1;
    }

    std::string line;
    getline(netInterfaces, line); // Skip header line

    while (getline(netInterfaces, line)) {
        std::vector<std::string> tokens = split(line, ':');
        if (tokens.size() >= 2) {
            std::string interfaceName = tokens[0];
            std::cout << "Interface Name: " << interfaceName << std::endl;
        }
    }

    netInterfaces.close();
    return 0;
}
