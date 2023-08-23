#include <iostream>
#include <fstream>
#include <string>

std::string getMotherboardInfo(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return "N/A";
    }

    std::string line;
    std::getline(file, line);
    file.close();

    return line;
}

int main() {
    std::string motherboardName = getMotherboardInfo("/sys/class/dmi/id/board_vendor");
    std::string motherboardVersion = getMotherboardInfo("/sys/class/dmi/id/board_version");

    std::cout << "Motherboard Name: " << motherboardName << std::endl;
    std::cout << "Motherboard Version: " << motherboardVersion << std::endl;

    return 0;
}
