#include <iostream>
#include <cstdio>

int main() {
    //BIOS information on macOS is not straightforward; you may use system_profiler for hardware info
    FILE* pipe = popen("system_profiler SPHardwareDataType", "r");
    if (pipe) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            std::cout << buffer;
        }
        pclose(pipe);
    }

    return 0;
}
