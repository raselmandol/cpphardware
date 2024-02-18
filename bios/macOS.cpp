//use efiFile, efiInfo, FirmwareFeatures
#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ifstream efiFile("/System/Library/CoreServices/SystemVersion.plist");
    if (!efiFile.is_open()) {
        std::cerr << "Failed to open EFI information file" << std::endl;
        return 1;
    }

    std::stringstream buffer;
    buffer << efiFile.rdbuf();
    std::string efiInfo = buffer.str();
    size_t versionPos = efiInfo.find("<key>FirmwareFeatures</key>");
    if (versionPos != std::string::npos) {
        size_t start = efiInfo.find("<string>", versionPos);
        size_t end = efiInfo.find("</string>", start);
        if (start != std::string::npos && end != std::string::npos) {
            std::string efiVersion = efiInfo.substr(start + 8, end - start - 8);
            std::cout << "EFI Version: " << efiVersion << std::endl;
        }
    }

    efiFile.close();
    return 0;
}
