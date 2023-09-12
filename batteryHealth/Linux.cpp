#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream chargeCycleFile("/sys/class/power_supply/BAT0/charge_full");
    if (chargeCycleFile.is_open()) {
        int chargeFull, chargeNow;
        chargeCycleFile >> chargeFull;
        chargeCycleFile.close();

        std::ifstream chargeNowFile("/sys/class/power_supply/BAT0/charge_now");
        if (chargeNowFile.is_open()) {
            chargeNowFile >> chargeNow;
            chargeNowFile.close();

            double batteryHealth = (static_cast<double>(chargeNow) / chargeFull) * 100.0;

            if (batteryHealth >= 80.0) {
                std::cout << "Battery Health: Good" << std::endl;
            } else if (batteryHealth >= 60.0) {
                std::cout << "Battery Health: Fair" << std::endl;
            } else {
                std::cout << "Battery Health: Poor" << std::endl;
            }
        } else {
            std::cerr << "Failed to retrieve charge_now." << std::endl;
        }
    } else {
        std::cerr << "Failed to retrieve charge_full." << std::endl;
    }

    return 0;
}
