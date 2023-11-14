#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream tempFile("/sys/class/thermal/thermal_zone0/temp");
    std::string temperature;

    if (tempFile.is_open()) {
        std::getline(tempFile, temperature);
        tempFile.close();

        double tempCelsius = std::stod(temperature) / 1000.0;
        std::cout << "GPU Temperature: " << tempCelsius << " degrees Celsius" << std::endl;
    } else {
        std::cerr << "Failed to open temperature file." << std::endl;
    }

    return 0;
}
