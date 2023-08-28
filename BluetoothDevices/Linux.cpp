#include <iostream>
#include <gio/gio.h>

int main() {
    g_autoptr(GDBusProxy) manager = nullptr;
    manager = g_dbus_proxy_new_for_bus_sync(
        G_BUS_TYPE_SYSTEM,
        G_DBUS_PROXY_FLAGS_NONE,
        nullptr,
        "org.bluez",
        "/",
        "org.bluez.Manager",
        nullptr, nullptr);

    g_autoptr(GVariant) result = nullptr;
    result = g_dbus_proxy_call_sync(
        manager,
        "ListAdapters",
        nullptr,
        G_DBUS_CALL_FLAGS_NONE,
        -1,
        nullptr,
        nullptr);

    GVariantIter iter;
    g_variant_iter_init(&iter, g_variant_get_child_value(result, 0));
    const gchar* objectPath;
    while (g_variant_iter_next(&iter, "o", &objectPath)) {
        std::cout << "Bluetooth Adapter Object Path: " << objectPath << std::endl;
    }

    return 0;
}
