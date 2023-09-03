#include <iostream>
#import <Cocoa/Cocoa.h>

int main() {
    NSArray<NSScreen*>* screens = [NSScreen screens];
    for (int i = 0; i < screens.count; ++i) {
        NSScreen* screen = screens[i];
        NSRect frame = [screen frame];
        std::cout << "Screen " << i << " Width: " << frame.size.width << " Height: " << frame.size.height << std::endl;
        //Print other display details as needed
    }

    return 0;
}
