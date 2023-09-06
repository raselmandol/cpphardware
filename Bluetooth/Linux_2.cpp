#include <stdio.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/hci.h>
#include <bluetooth/hci_lib.h>

int main() {
    inquiry_info* ii = NULL;
    int max_rsp = 255;
    int num_rsp = 0;
    int dev_id = hci_get_route(NULL);
    int sock = hci_open_dev(dev_id);

    if (dev_id < 0 || sock < 0) {
        perror("Cannot open Bluetooth socket");
        return 1;
    }

    ii = (inquiry_info*)malloc(max_rsp * sizeof(inquiry_info));
    num_rsp = hci_inquiry(dev_id, 8, max_rsp, NULL, &ii, IREQ_CACHE_FLUSH);

    for (int i = 0; i < num_rsp; i++) {
        char addr[19] = { 0 };
        ba2str(&(ii + i)->bdaddr, addr);
        printf("Device Address: %s\n", addr);

        char name[248] = { 0 };
        if (hci_read_remote_name(sock, &(ii + i)->bdaddr, sizeof(name), name, 0) < 0) {
            strcpy(name, "unknown");
        }
        printf("Device Name: %s\n", name);
        //Print other Bluetooth device details as needed
    }

    free(ii);
    close(sock);

    return 0;
}
