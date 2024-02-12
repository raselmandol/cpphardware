//accessing libusb_init
#include <iostream>
#include <libusb-1.0/libusb.h>

int main() {
    libusb_context* ctx = nullptr;
    libusb_device** devices;
    ssize_t count;

    if (libusb_init(&ctx) < 0) {
        std::cerr << "libusb initialization failed" << std::endl;
        return 1;
    }

    count = libusb_get_device_list(ctx, &devices);
    if (count < 0) {
        std::cerr << "libusb_get_device_list failed" << std::endl;
        libusb_exit(ctx);
        return 1;
    }

    for (ssize_t i = 0; i < count; ++i) {
        libusb_device* device = devices[i];
        libusb_device_descriptor descriptor;
        if (libusb_get_device_descriptor(device, &descriptor) == 0) {
            std::cout << "Device Vendor ID: " << std::hex << descriptor.idVendor << std::endl;
            std::cout << "Device Product ID: " << std::hex << descriptor.idProduct << std::endl;
        }
    }

    libusb_free_device_list(devices, 1);
    libusb_exit(ctx);

    return 0;
}
