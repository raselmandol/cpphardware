#include <iostream>
#include <IOKit/usb/IOUSBLib.h>
#include <IOKit/IOKitLib.h>

int main() {
    CFMutableDictionaryRef matchingDictionary = IOServiceMatching(kIOUSBDeviceClassName);
    io_iterator_t iterator = 0;
    kern_return_t kr = IOServiceGetMatchingServices(kIOMasterPortDefault, matchingDictionary, &iterator);

    if (kr != KERN_SUCCESS) {
        std::cerr << "IOServiceGetMatchingServices failed" << std::endl;
        return 1;
    }

    io_service_t usbDevice;
    while ((usbDevice = IOIteratorNext(iterator))) {
        CFMutableDictionaryRef deviceProperties = nullptr;
        kr = IORegistryEntryCreateCFProperties(usbDevice, &deviceProperties, kCFAllocatorDefault, 0);

        if (kr == KERN_SUCCESS && deviceProperties) {
            CFStringRef productName = (CFStringRef)CFDictionaryGetValue(deviceProperties, CFSTR(kUSBProductString));
            if (productName) {
                std::wstring_convert<std::codecvt_utf8_utf16<UInt16>, UInt16> converter;
                std::wcout << "Device Product Name: " << converter.to_bytes(CFStringGetCStringPtr(productName, kCFStringEncodingUTF8)) << std::endl;
                // You can retrieve and print more USB device information here.
            }
        }

        IOObjectRelease(usbDevice);
    }

    IOObjectRelease(iterator);

    return 0;
}
