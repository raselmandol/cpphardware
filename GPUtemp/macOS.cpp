#include <iostream>
#include <cstdio>

int main() {
    FILE* pipe = popen("system_profiler SPDisplaysDataType", "r");
    if (pipe) {
        char buffer[128];
        bool captureTemperature = false;

        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            std::string line(buffer);

            //containing "Temperature Sensor"
            if (line.find("Temperature Sensor") != std::string::npos) {
                captureTemperature = true;
            }

            if (captureTemperature) {
                std::cout << line;
            }
        }
        pclose(pipe);
    }

    return 0;
}
