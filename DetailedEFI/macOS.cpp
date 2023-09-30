//using nvram

#include <iostream>
#include <cstdio>

int main() {
    FILE* pipe = popen("nvram", "r");
    if (!pipe) {
        std::cerr << "Failed to run nvram" << std::endl;
        return 1;
    }
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::cout << buffer;
    }
    pclose(pipe);
    return 0;
}
