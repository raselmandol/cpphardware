#include <iostream>
#include <cstdio>

int main() {
    FILE* pipe = popen("system_profiler SPHardwareDataType", "r");
    if (pipe) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            std::string line(buffer);
            if (line.find("Model Identifier") != std::string::npos || line.find("Processor Name") != std::string::npos) {
                std::cout << line;
            }
        }
        pclose(pipe);
    }

    return 0;
}
