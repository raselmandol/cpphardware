#include <iostream>
#include <Cocoa/Cocoa.h>

int main() {
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    NSArray* screens = [NSScreen screens];

    for (int i = 0; i < [screens count]; ++i) {
        NSScreen* screen = [screens objectAtIndex:i];
        NSRect frame = [screen frame];
        std::cout << "Screen " << i << ":\n";
        std::cout << "Width: " << frame.size.width << " points\n";
        std::cout << "Height: " << frame.size.height << " points\n";
        std::cout << std::endl;
    }

    [pool release];
    return 0;
}
