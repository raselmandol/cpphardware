#include <iostream>
#include <X11/Xlib.h>
#include <X11/Xutil.h>

int main() {
    Display* display = XOpenDisplay(NULL);
    if (display == nullptr) {
        std::cerr << "Unable to open X display." << std::endl;
        return 1;
    }

    int screenCount = ScreenCount(display);
    for (int screen = 0; screen < screenCount; ++screen) {
        Screen* xScreen = ScreenOfDisplay(display, screen);
        std::cout << "Screen " << screen << " Width: " << xScreen->width << " Height: " << xScreen->height << std::endl;
        //Print other display details as needed
    }

    XCloseDisplay(display);
    return 0;
}
