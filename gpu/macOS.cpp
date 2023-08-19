#include <iostream>
#include <IOKit/IOKitLib.h>
#include <IOKit/graphics/IOGraphicsLib.h>

int main() {
    CFMutableDictionaryRef serviceMatching = IOServiceMatching("IOAccelerator");

    io_iterator_t iterator;
    kern_return_t result = IOServiceGetMatchingServices(kIOMasterPortDefault, serviceMatching, &iterator);
    
    if (result != KERN_SUCCESS) {
        std::cerr << "Failed to get matching services" << std::endl;
        return 1;
    }

    io_registry_entry_t acceleratorService;
    while ((acceleratorService = IOIteratorNext(iterator))) {
        CFMutableDictionaryRef properties;
        result = IORegistryEntryCreateCFProperties(acceleratorService, &properties, kCFAllocatorDefault, kNilOptions);
        if (result != KERN_SUCCESS) {
            std::cerr << "Failed to get properties" << std::endl;
            IOObjectRelease(acceleratorService);
            continue;
        }

        CFStringRef name = (CFStringRef)CFDictionaryGetValue(properties, CFSTR("IOAcceleratorName"));
        if (name) {
            std::cout << "GPU Name: " << CFStringGetCStringPtr(name, kCFStringEncodingUTF8) << std::endl;
        }

        CFRelease(properties);
        IOObjectRelease(acceleratorService);
    }

    IOObjectRelease(iterator);

    return 0;
}
