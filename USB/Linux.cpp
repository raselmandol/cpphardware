#include <iostream>
#include <dirent.h>
#include <fstream>
#include <string>

std::string getUsbDeviceName(const std::string& devPath) {
    std::string deviceName;
    std::ifstream infile(devPath + "/product");
    if (infile.good()) {
        std::getline(infile, deviceName);
    }
    return deviceName;
}

int main() {
    DIR* dir = opendir("/sys/bus/usb/devices");
    if (dir == nullptr) {
        std::cerr << "Failed to open directory." << std::endl;
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_name[0] != '.') {
            std::string usbDevicePath = "/sys/bus/usb/devices/" + std::string(entry->d_name);
            std::string deviceName = getUsbDeviceName(usbDevicePath);
            if (!deviceName.empty()) {
                std::cout << "USB Device: " << deviceName << std::endl;
            }
        }
    }

    closedir(dir);
    return 0;
}
