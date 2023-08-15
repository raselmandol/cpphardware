#include <iostream>
#include <sys/utsname.h>

int main() {
    struct utsname system_info;
    if (uname(&system_info) == 0) {
        std::cout << "Kernel Name: " << system_info.sysname << std::endl;
        std::cout << "Node Name: " << system_info.nodename << std::endl;
        std::cout << "Kernel Release: " << system_info.release << std::endl;
        std::cout << "Kernel Version: " << system_info.version << std::endl;
        std::cout << "Machine Type: " << system_info.machine << std::endl;
    } else {
        std::cerr << "Error retrieving system information." << std::endl;
        return 1;
    }
    return 0;
}
