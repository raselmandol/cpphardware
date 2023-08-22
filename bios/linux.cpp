#include <iostream>
#include <fstream>
#include <string>

std::string getBiosInfo(const std::string& filename) {
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
    std::string biosVendor = getBiosInfo("/sys/class/dmi/id/bios_vendor");
    std::string biosVersion = getBiosInfo("/sys/class/dmi/id/bios_version");
    std::string biosReleaseDate = getBiosInfo("/sys/class/dmi/id/bios_date");

    std::cout << "BIOS Vendor: " << biosVendor << std::endl;
    std::cout << "BIOS Version: " << biosVersion << std::endl;
    std::cout << "BIOS Release Date: " << biosReleaseDate << std::endl;

    return 0;
}
