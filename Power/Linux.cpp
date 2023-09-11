#include <iostream>
#include <fstream>

int main() {
    std::ifstream batteryInfo("/sys/class/power_supply/BAT0/status");
    if (batteryInfo.is_open()) {
        std::string status;
        std::getline(batteryInfo, status);

        std::ifstream batteryCapacity("/sys/class/power_supply/BAT0/capacity");
        if (batteryCapacity.is_open()) {
            std::string capacity;
            std::getline(batteryCapacity, capacity);

            std::cout << "Battery Status: " << status << std::endl;
            std::cout << "Battery Percentage: " << capacity << "%" << std::endl;
        } else {
            std::cerr << "Failed to retrieve battery capacity." << std::endl;
        }

        batteryInfo.close();
    } else {
        std::cerr << "Failed to retrieve battery status." << std::endl;
    }

    return 0;
}
