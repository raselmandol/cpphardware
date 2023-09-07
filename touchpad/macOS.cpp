#include <CoreFoundation/CoreFoundation.h>
#include <IOKit/hid/IOHIDManager.h>
#include <stdio.h>

void deviceAdded(void* context, IOReturn result, void* sender, IOHIDDeviceRef device) {
    if (device) {
        printf("Touchpad Device Added\n");
    }
}

int main() {
    IOHIDManagerRef manager = IOHIDManagerCreate(kCFAllocatorDefault, kIOHIDOptionsTypeNone);
    if (!manager) {
        fprintf(stderr, "Failed to create IOHIDManager\n");
        return 1;
    }

    IOHIDManagerSetDeviceMatching(manager, NULL);
    IOHIDManagerRegisterDeviceMatchingCallback(manager, deviceAdded, NULL);
    IOHIDManagerScheduleWithRunLoop(manager, CFRunLoopGetMain(), kCFRunLoopDefaultMode);

    CFRunLoopRun();

    return 0;
}
