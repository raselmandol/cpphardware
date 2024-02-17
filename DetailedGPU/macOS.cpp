//using IOGraphicsLib
#include <iostream>
#include <IOKit/graphics/IOGraphicsLib.h>

int main() {
    io_iterator_t iterator;
    kern_return_t kr = IOServiceGetMatchingServices(
        kIOMasterPortDefault,
        IOServiceMatching("IOPCIDevice"),
        &iterator
    );

    if (kr != KERN_SUCCESS) {
        std::cerr << "Failed to get GPU information." << std::endl;
        return 1;
    }

    io_registry_entry_t device;
    while ((device = IOIteratorNext(iterator)) != MACH_PORT_NULL) {
        CFTypeRef name = IORegistryEntrySearchCFProperty(
            device,
            kIOServicePlane,
            CFSTR("IONameMatch"),
            kCFAllocatorDefault,
            kIORegistryIterateRecursively
        );

        if (name != nullptr) {
            CFStringRef nameStr = CFStringCreateWithFormat(
                kCFAllocatorDefault,
                nullptr,
                CFSTR("%@"),
                name
            );

            std::cout << "GPU Name: " << CFStringGetCStringPtr(nameStr, kCFStringEncodingUTF8) << std::endl;
            CFRelease(nameStr);
        }

        IOObjectRelease(device);
    }

    IOObjectRelease(iterator);

    return 0;
}
/*
_________MANDOL_0101_RASEL___
_________MANDOL_0101_RASEL___
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_________MANDOL_0101_RASEL___
_________MANDOL_0101_RASEL___

_____010101_____________________
_0101010101010__________________
010101010101010_________________
01010101010101011_______________
01010101010101010_______________
01010101010101010101010101______
01010101010101010101010101010___
0101010100101010101010101010101_
01010101010101010101010101010101
010101010101010101010101010__01_
01010101010101010100101010101___
01010100101010010101010101______
01010101010101010101010_________
1010101010101010101_____________
01010101010101__________________
101010101_______________________
010101__________________________
10______________________________
*/
