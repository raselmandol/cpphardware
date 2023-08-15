#include <iostream>
#include <libudev.h>

int main() {
    udev *udevContext = udev_new();
    if (!udevContext) {
        std::cerr << "Failed to create udev context" << std::endl;
        return 1;
    }
    udev_enumerate *enumerator = udev_enumerate_new(udevContext);
    udev_enumerate_add_match_subsystem(enumerator, "net");
    udev_enumerate_scan_devices(enumerator);
    udev_list_entry *deviceList = udev_enumerate_get_list_entry(enumerator);
    udev_list_entry *deviceEntry;
    udev_list_entry_foreach(deviceEntry, deviceList) {
        const char *path = udev_list_entry_get_name(deviceEntry);
        udev_device *device = udev_device_new_from_syspath(udevContext, path);

        if (device) {
            std::cout << "Device Path: " << path << std::endl;
            std::cout << "Device Name: " << udev_device_get_sysname(device) << std::endl;
            std::cout << "Device ID: " << udev_device_get_devnum(device) << std::endl;
            std::cout << "Kernel Driver: " << udev_device_get_driver(device) << std::endl;
            std::cout << "Interface Name: " << udev_device_get_property_value(device, "INTERFACE") << std::endl;
            std::cout << "MAC Address: " << udev_device_get_sysattr_value(device, "address") << std::endl;
            std::cout << "==================================" << std::endl;
            udev_device_unref(device);
        }
    }
    udev_enumerate_unref(enumerator);
    udev_unref(udevContext);
    return 0;
}
