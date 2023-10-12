//ref to Intel PowerGadget
#include <iostream>
#include <cstdlib>

int main() {
    //Use the system function to execute an external command (e.g., Intel Power Gadget).
    const char* command = "/path/to/temperature-monitoring-tool";
    int exitCode = std::system(command);

    if (exitCode == 0) {
        //std::cout << "CPU Temperature: T°C" << std::endl;
      //print the original one here
    } else {
        std::cerr << "Failed to retrieve CPU temperature." << std::endl;
    }

    return 0;
}
