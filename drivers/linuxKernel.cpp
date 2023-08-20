#include <iostream>
#include <cstdio>

int main() {
    FILE* fp = popen("lsmod", "r");
    if (fp == nullptr) {
        std::cerr << "Failed to execute lsmod" << std::endl;
        return 1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp) != nullptr) {
        std::cout << buffer;
    }
    pclose(fp);
    return 0;
}
