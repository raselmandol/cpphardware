#include <iostream>
#include <cstdio>

int main() {
    FILE* pipe = popen("lshw -class system", "r");
    if (pipe) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            std::string line(buffer);
            if (line.find("product:") != std::string::npos || line.find("vendor:") != std::string::npos) {
                std::cout << line;
            }
        }
        pclose(pipe);
    }

    return 0;
}
