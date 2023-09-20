#include <iostream>
#include <windows.h>

int main() {
    SYSTEM_POWER_STATUS powerStatus;
    if (GetSystemPowerStatus(&powerStatus)) {
        std::cout << "Battery Status: " << (powerStatus.BatteryFlag == 8 ? "Charging" : "Not Charging") << std::endl;
        std::cout << "Battery Percentage: " << static_cast<int>(powerStatus.BatteryLifePercent) << "%" << std::endl;
        std::cout << "AC Line Status: " << (powerStatus.ACLineStatus == 1 ? "Online" : "Offline") << std::endl;
      //print more here
    } else {
        std::cerr << "Failed to retrieve power status." << std::endl;
    }

    return 0;
}
