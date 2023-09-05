#include <stdio.h>
#include <CoreGraphics/CoreGraphics.h>

int main() {
    CFArrayRef displays = CGDisplayCopyAllDisplayModes(kCGDirectMainDisplay);

    for (CFIndex i = 0; i < CFArrayGetCount(displays); i++) {
        CGDisplayModeRef mode = (CGDisplayModeRef)CFArrayGetValueAtIndex(displays, i);
        printf("Display %ld\n", i + 1);
        printf("Width: %ld Height: %ld\n", CGDisplayModeGetWidth(mode), CGDisplayModeGetHeight(mode));
    }

    CFRelease(displays);
    return 0;
}
