//will update later

#include <iostream>
#include <cstdio>

int main() {
    FILE* pipe = popen("system_profiler SPDisplaysDataType", "r");
    if (pipe) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            std::cout << buffer;
        }
        pclose(pipe);
    }

    return 0;
}
