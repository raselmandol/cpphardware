#include <iostream>
#include <fstream>
#include <string>

std::string readValueFromFile(const std::string& filePath) {
    std::ifstream file(filePath);
    if (!file) {
        return "N/A";
    }
    std::string value;
    file >> value;
    return value;
}

int main() {
    //to power-related files
    const std::string batteryStatusPath = "/sys/class/power_supply/BAT0/status";
    const std::string batteryCapacityPath = "/sys/class/power_supply/BAT0/capacity";
    const std::string acAdapterStatusPath = "/sys/class/power_supply/AC/online";

    //battery status
    std::string batteryStatus = readValueFromFile(batteryStatusPath);

    //battery capacity (percentage)
    std::string batteryCapacity = readValueFromFile(batteryCapacityPath);

    //AC adapter status
    std::string acAdapterStatus = readValueFromFile(acAdapterStatusPath);

    //retrieved information
    std::cout << "Battery Status: " << batteryStatus << std::endl;
    std::cout << "Battery Percentage: " << batteryCapacity << "%" << std::endl;
    std::cout << "AC Adapter Status: " << (acAdapterStatus == "1" ? "Online" : "Offline") << std::endl;

    return 0;
}
