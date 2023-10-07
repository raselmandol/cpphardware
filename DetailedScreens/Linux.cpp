#include <iostream>
#include <X11/Xlib.h>

int main() {
    Display* display = XOpenDisplay(nullptr);
    if (display) {
        int screenCount = ScreenCount(display);

        for (int screen = 0; screen < screenCount; ++screen) {
            Screen* xScreen = ScreenOfDisplay(display, screen);
            std::cout << "Screen " << screen << ":\n";
            std::cout << "Width: " << WidthOfScreen(xScreen) << " pixels\n";
            std::cout << "Height: " << HeightOfScreen(xScreen) << " pixels\n";
            std::cout << std::endl;
        }

        XCloseDisplay(display);
    } else {
        std::cerr << "Failed to open X display" << std::endl;
        return 1;
    }

    return 0;
}
