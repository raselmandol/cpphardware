
#include <iostream>
#include <CoreFoundation/CoreFoundation.h>
#include <SystemConfiguration/SCDynamicStore.h>
#include <SystemConfiguration/SCSchemaDefinitions.h>

int main() {
    //creating SCDynamicStore
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
