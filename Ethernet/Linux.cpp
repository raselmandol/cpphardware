#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    if (sock == -1) {
        perror("Failed to create socket");
        return 1;
    }

    struct ifreq ifr;
    //eth0 copy
    strcpy(ifr.ifr_name, "eth0");

    if (ioctl(sock, SIOCGIFFLAGS, &ifr) != -1 && (ifr.ifr_flags & IFF_UP)) {
        printf("Connected to a network (possibly Ethernet).\n");
    } else {
        printf("Not connected to a network.\n");
    }

    close(sock);
    return 0;
}
