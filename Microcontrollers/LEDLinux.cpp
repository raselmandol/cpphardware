#include <iostream>
#include <fstream>
#include <unistd.h>

int main() {
    //directly open handler// gpioPath
    const std::string gpioPath = "/sys/class/gpio/gpio17";
    //exportFile Path
    std::ofstream exportFile("/sys/class/gpio/export");

    if (!exportFile.is_open()) {
        std::cerr << "Error: Unable to export GPIO pin." << std::endl;
        return 1;
    }

    exportFile << "17";
    exportFile.close();

    std::ofstream directionFile(gpioPath + "/direction");
    if (!directionFile.is_open()) {
        std::cerr << "Error: Unable to set GPIO direction." << std::endl;
        return 1;
    }

    directionFile << "out";
    directionFile.close();

    while (true) {
        std::ofstream valueFile(gpioPath + "/value");
        if (!valueFile.is_open()) {
            std::cerr << "Error: Unable to set GPIO value." << std::endl;
            return 1;
        }

        valueFile << "1";
        valueFile.close();
        usleep(1000000); 

        valueFile.open(gpioPath + "/value");
        if (!valueFile.is_open()) {
            std::cerr << "Error: Unable to set GPIO value." << std::endl;
            return 1;
        }

        valueFile << "0"; 
        valueFile.close();
        usleep(1000000); 
    }

    return 0;
}
