#include <stdio.h>
#include <X11/Xlib.h>
#include <X11/extensions/Xrandr.h>

int main() {
    Display* display = XOpenDisplay(NULL);
    if (display == NULL) {
        fprintf(stderr, "Unable to open X display.\n");
        return 1;
    }

    Window root = DefaultRootWindow(display);
    XRRScreenResources* resources = XRRGetScreenResources(display, root);

    for (int i = 0; i < resources->noutput; i++) {
        XRROutputInfo* outputInfo = XRRGetOutputInfo(display, resources, resources->outputs[i]);

        if (outputInfo->connection == RR_Connected) {
            printf("Output Name: %s\n", outputInfo->name);
        }

        XRRFreeOutputInfo(outputInfo);
    }

    XRRFreeScreenResources(resources);
    XCloseDisplay(display);

    return 0;
}
