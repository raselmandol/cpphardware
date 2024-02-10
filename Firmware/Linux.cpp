//using dmidecode -t bios
#include <iostream>
#include <cstdio>

int main() {
    FILE* fp = popen("dmidecode -t bios", "r");
    if (!fp) {
        std::cerr << "Failed to execute dmidecode" << std::endl;
        return 1;
    }
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        std::cout << buffer;
    }

    pclose(fp);

    return 0;
}
