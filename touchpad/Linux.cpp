
#include <stdio.h>
#include <libinput.h>

int main() {
    struct libinput* li;
    struct libinput_event* event;

    li = libinput_path_create_context(&interface, NULL);

    if (li == NULL) {
        fprintf(stderr, "Failed to create libinput context\n");
        return 1;
    }

    while (1) {
        libinput_dispatch(li);

        while ((event = libinput_get_event(li))) {
            switch (libinput_event_get_type(event)) {
                case LIBINPUT_EVENT_DEVICE_ADDED:
                    printf("Touchpad Device Added\n");
                    break;
                default:
                    break;
            }
            libinput_event_destroy(event);
        }
    }

    return 0;
}
