#include <iostream>
#include <cstdlib>

int main() {
    const char* command = "smartctl -H /dev/disk0";

    std::cout << "Checking hard disk health..." << std::endl;
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        std::cerr << "Error executing smartctl." << std::endl;
        return 1;
    }

    char buffer[128];
    std::string result = "";

    while (!feof(pipe)) {
        if (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }
    }
    pclose(pipe);

    if (result.find("PASSED") != std::string::npos) {
        std::cout << "Hard disk health: PASSED" << std::endl;
    } else {
        std::cout << "Hard disk health: FAILED" << std::endl;
    }

    return 0;
}
