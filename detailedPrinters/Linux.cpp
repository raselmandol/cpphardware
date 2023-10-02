#include <cups/cups.h>
#include <iostream>

int main() {
    int numPrinters;
    cups_dest_t* dests;

    numPrinters = cupsGetDests(&dests);

    if (numPrinters <= 0) {
        std::cerr << "No printers found" << std::endl;
        return 1;
    }
    for (int i = 0; i < numPrinters; i++) {
        std::cout << "Printer Name: " << dests[i].name << std::endl;
        std::cout << "Description: " << dests[i].info << std::endl;
        std::cout << "Location: " << dests[i].location << std::endl;
        std::cout << std::endl;
    }
    cupsFreeDests(numPrinters, dests);
    return 0;
}
