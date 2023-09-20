#include <iostream>
#include <IOKit/IOKitLib.h>

int main() {
    CFTypeRef powerInfo = IOPSCopyPowerSourcesInfo();
    CFArrayRef powerSources = IOPSCopyPowerSourcesList(powerInfo);

    if (powerSources) {
        CFDictionaryRef powerSource = static_cast<CFDictionaryRef>(CFArrayGetValueAtIndex(powerSources, 0));
        if (powerSource) {
            std::cout << "Battery Present: " << (CFDictionaryContainsKey(powerSource, CFSTR(kIOPSIsPresent)) ? "Yes" : "No") << std::endl;
            std::cout << "Battery Charging: " << (CFDictionaryContainsKey(powerSource, CFSTR(kIOPSIsCharging)) ? "Yes" : "No") << std::endl;
            //other Power informations you should print here
        }

        CFRelease(powerSources);
    } else {
        std::cerr << "Failed to retrieve power source information." << std::endl;
    }

    if (powerInfo) {
        CFRelease(powerInfo);
    }

    return 0;
}
