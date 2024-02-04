#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream temperatureFile("/sys/class/hwmon/hwmon0/temp1_input");
    if (temperatureFile) {
        int temperature;
        temperatureFile >> temperature;
        temperatureFile.close();
        double tempCelsius = static_cast<double>(temperature) / 1000;
        std::cout << "CPU Temperature: " << tempCelsius << "°C" << std::endl;
      
    } else {
        std::cerr << "Unable to open temperature file." << std::endl;
        return 1;
    }

    return 0;
}
