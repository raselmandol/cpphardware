//will update later
//for now this extracts the GPU details using connector 
#include <iostream>
#include <cstdio>

int main() {
    //just using the pipe and implementation of sys SPD
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
