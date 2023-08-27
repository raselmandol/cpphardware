#include <iostream>
#include <cstdlib>

int main() {
    FILE* pipe = popen("/usr/sbin/lpstat -p", "r");
    if (pipe) {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            std::cout << "Printer Name: " << buffer;
        }
        pclose(pipe);
    }
    return 0;
}
