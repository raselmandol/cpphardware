//no direct API for Windows
//comparing with capacity
#include <iostream>
#include <Windows.h>

int main() {
    SYSTEM_POWER_STATUS powerStatus;
    if (GetSystemPowerStatus(&powerStatus)) {
        double batteryCapacity = powerStatus.BatteryLifePercent;
        
        if (batteryCapacity >= 80.0) {
            std::cout << "Battery Health: Good" << std::endl;
        } else if (batteryCapacity >= 60.0) {
            std::cout << "Battery Health: Fair" << std::endl;
        } else {
            std::cout << "Battery Health: Poor" << std::endl;
        }
    } else {
        std::cerr << "Failed to retrieve power status." << std::endl;
    }

    return 0;
}
