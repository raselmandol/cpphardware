#include <iostream>
#include <cstdio>

int main() {
    FILE* fp = popen("kextstat", "r");
    if (fp == nullptr) {
        std::cerr << "Failed to execute kextstat" << std::endl;
        return 1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
        std::cout << buffer;
    }

    pclose(fp);
    return 0;
}
