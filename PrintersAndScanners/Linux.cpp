#include <iostream>
#include <cups/cups.h>

int main() {
    cups_dest_t* dests;
    int numDest = cupsGetDests(&dests);
    for (int i = 0; i < numDest; ++i) {
        std::cout << "Printer Name: " << dests[i].name << std::endl;
    }
    cupsFreeDests(numDest, dests);
    return 0;
}
