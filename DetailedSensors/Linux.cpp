#include <iostream>
#include <cstdio>

int main() {
    FILE* pipe = popen("sensors", "r");
    if (!pipe) {
        std::cerr << "Failed to run 'sensors' command" << std::endl;
        return 1;
    }
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::cout << buffer;
    }
    pclose(pipe);
    return 0;
}
