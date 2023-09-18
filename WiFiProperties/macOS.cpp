#include <iostream>
#include <CoreFoundation/CoreFoundation.h>
#include <SystemConfiguration/SCDynamicStore.h>
#include <SystemConfiguration/SCSchemaDefinitions.h>

int main() {
    SCDynamicStoreRef store = SCDynamicStoreCreate(kCFAllocatorDefault, CFSTR("WifiInfo"), nullptr, nullptr);
    if (!store) {
        std::cerr << "Failed to create SCDynamicStore." << std::endl;
        return 1;
    }
    CFPropertyListRef info = SCDynamicStoreCopyValue(store, CFSTR("State:/Network/Interface/en0/AirPort"));
    if (!info) {
        std::cerr << "Failed to retrieve WiFi info." << std::endl;
        CFRelease(store);
        return 1;
    }
    CFShow(info);
    CFRelease(info);
    CFRelease(store);

    return 0;
}
