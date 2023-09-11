#include <iostream>
#include <Windows.h>

int main() {
    SYSTEM_POWER_STATUS powerStatus;
    if (GetSystemPowerStatus(&powerStatus)) {
        std::cout << "AC Line Status: " << (powerStatus.ACLineStatus == 1 ? "Online" : "Offline") << std::endl;
        std::cout << "Battery Percentage: " << static_cast<int>(powerStatus.BatteryLifePercent) << "%" << std::endl;
        std::cout << "Battery Charging: " << (powerStatus.BatteryFlag & 8 ? "Yes" : "No") << std::endl;
    } else {
        std::cerr << "Failed to retrieve power status." << std::endl;
    }

    return 0;
}
