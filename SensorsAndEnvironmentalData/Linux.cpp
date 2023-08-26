#include <iostream>
#include <fstream>
#include <string>

std::string readSensorValue(const std::string& path) {
    std::ifstream file(path);
    if (file.is_open()) {
        std::string value;
        file >> value;
        return value;
    }
    return "N/A";
}

int main() {
    std::string temperatureValue = readSensorValue("/sys/class/thermal/thermal_zone0/temp");
    float temperature = std::stoi(temperatureValue) / 1000.0;
    std::cout << "Temperature: " << temperature << " °C" << std::endl;

    return 0;
}
