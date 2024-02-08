#include <iostream>
#include <cstdio>

int main() {
    //popen dmidecode, "r"
    FILE* pipe = popen("dmidecode", "r");
    if (!pipe) {
        std::cerr << "Failed to run dmidecode" << std::endl;
        return 1;
    }

    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        std::cout << buffer;
    }
    pclose(pipe);
    return 0;
}
