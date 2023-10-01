#include <iostream>
#include <IOKit/IOKitLib.h>

int main() {
    kern_return_t result;
    io_iterator_t iterator;
    io_service_t service;

    result = IOServiceGetMatchingServices(kIOMasterPortDefault, IOServiceMatching("AppleLMUController"), &iterator);
    if (result != KERN_SUCCESS) {
        std::cerr << "Failed to get services" << std::endl;
        return 1;
    }
    while ((service = IOIteratorNext(iterator)) != IO_OBJECT_NULL) {
        CFMutableDictionaryRef properties = nullptr;
        result = IORegistryEntryCreateCFProperties(service, &properties, kCFAllocatorDefault, kNilOptions);
        if (result == KERN_SUCCESS && properties != nullptr) {
            CFStringRef name = static_cast<CFStringRef>(CFDictionaryGetValue(properties, CFSTR("Location")));
            CFNumberRef temperature = static_cast<CFNumberRef>(CFDictionaryGetValue(properties, CFSTR("Temperature")));

            if (name != nullptr && temperature != nullptr) {
                char nameBuffer[128];
                CFStringGetCString(name, nameBuffer, sizeof(nameBuffer), kCFStringEncodingUTF8);

                double temperatureValue;
                CFNumberGetValue(temperature, kCFNumberDoubleType, &temperatureValue);

                std::cout << "Sensor: " << nameBuffer << ", Temperature: " << temperatureValue << "°C" << std::endl;
            }
            CFRelease(properties);
        }
        IOObjectRelease(service);
    }
    IOObjectRelease(iterator);

    return 0;
}
