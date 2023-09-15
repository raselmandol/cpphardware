#include <iostream>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>
int main() {
    io_service_t service = IOServiceGetMatchingService(kIOMasterPortDefault, IOServiceMatching("IOPCIDevice"));
    if (service) {
        CFMutableDictionaryRef properties = NULL;
        if (IORegistryEntryCreateCFProperties(service, &properties, kCFAllocatorDefault, kNilOptions) == KERN_SUCCESS) {
            CFStringRef gpuName = (CFStringRef)CFDictionaryGetValue(properties, CFSTR("IOName"));
            if (gpuName) {
                std::cout << "GPU Name: " << CFStringGetCStringPtr(gpuName, kCFStringEncodingUTF8) << std::endl;
            }

            //You can access more GPU information from the properties dictionary
          //If you don't have a powerful GPU, go cry like me ::<
            CFRelease(properties);
        }
        IOObjectRelease(service);
    }
    return 0;
}
