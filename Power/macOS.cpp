#include <iostream>
#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/IOKitLib.h>

int main() {
    CFTypeRef powerInfo = IOPSCopyPowerSourcesInfo();
    CFArrayRef powerSources = IOPSCopyPowerSourcesList(powerInfo);

    if (powerSources) {
        CFIndex numPowerSources = CFArrayGetCount(powerSources);

        for (CFIndex i = 0; i < numPowerSources; i++) {
            CFDictionaryRef powerSource = IOPSGetPowerSourceDescription(powerInfo, CFArrayGetValueAtIndex(powerSources, i));

            if (powerSource) {
                CFStringRef powerSourceType = (CFStringRef)CFDictionaryGetValue(powerSource, CFSTR(kIOPSTypeKey));
                CFStringRef powerSourceName = (CFStringRef)CFDictionaryGetValue(powerSource, CFSTR(kIOPSNameKey));

                if (powerSourceType && powerSourceName) {
                    std::cout << "Power Source " << i + 1 << ":" << std::endl;
                    std::cout << "Type: " << CFStringGetCStringPtr(powerSourceType, kCFStringEncodingUTF8) << std::endl;
                    std::cout << "Name: " << CFStringGetCStringPtr(powerSourceName, kCFStringEncodingUTF8) << std::endl;
                }
            }
        }

        CFRelease(powerSources);
    } else {
        std::cerr << "Failed to retrieve power source information." << std::endl;
    }

    CFRelease(powerInfo);

    return 0;
}
