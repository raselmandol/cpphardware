//check 0!
#include <iostream>
#include <cstdio>

int main() {
    FILE* fp = popen("system_profiler SPHardwareDataType", "r");
    if (!fp) {
        std::cerr << "Failed to execute system_profiler" << std::endl;
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), fp)) {
        std::cout << buffer;
    }

    pclose(fp);

    return 0;
}
