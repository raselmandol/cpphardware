#include <iostream>
#include <libpci/pci.h>

int main() {
    pci_init();
    pci_filter_init(nullptr);
    pci_access* pacc = pci_alloc();

    if (!pacc) {
        std::cerr << "Failed to initialize libpci" << std::endl;
        return 1;
    }

    pci_fill_info(pacc, PCI_FILL_IDENT | PCI_FILL_CLASS);
    pci_device* pdev;

    for (pdev = pci_first_dev(pacc); pdev; pdev = pci_next_dev(pdev)) {
        const char* device_name = pci_lookup_name(pacc, pdev->device_class, 0);
        if (device_name) {
            std::cout << "GPU Name: " << device_name << std::endl;
        }
    }

    pci_cleanup(pacc);

    return 0;
}
