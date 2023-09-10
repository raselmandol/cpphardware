#include <iostream>
#include <cstdlib>

int main() {
    int status = system("smartctl -H /dev/sda"); //Replace /dev/sda with the appropriate device name

    if (WIFEXITED(status) && WEXITSTATUS(status) == 0) {
        std::cout << "Drive is healthy." << std::endl;
    } else {
        std::cerr << "Drive may have issues." << std::endl;
    }

    return 0;
}
