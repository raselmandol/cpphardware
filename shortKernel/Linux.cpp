#include <iostream>
#include <sys/utsname.h>

int main() {
    struct utsname info;
    if (uname(&info) == 0) {
        std::cout << "Linux Kernel Information:" << std::endl;
        std::cout << "Release: " << info.release << std::endl;
        std::cout << "Version: " << info.version << std::endl;
        std::cout << "Machine: " << info.machine << std::endl;
    } else {
        std::cerr << "Error getting Linux kernel information." << std::endl;
        return 1;
    }

    return 0;
}
