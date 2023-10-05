#include <iostream>
#include <ifaddrs.h>
#include <net/if_dl.h>

int main() {
    struct ifaddrs* ifaList = nullptr;
    if (getifaddrs(&ifaList) != 0) {
        std::cerr << "getifaddrs failed" << std::endl;
        return 1;
    }

    struct ifaddrs* ifa = ifaList;
    while (ifa) {
        if (ifa->ifa_addr->sa_family == AF_LINK) {
            struct sockaddr_dl* sdl = (struct sockaddr_dl*)ifa->ifa_addr;
            if (sdl->sdl_type == IFT_ETHER) {
                char name[IFNAMSIZ];
                strncpy(name, ifa->ifa_name, IFNAMSIZ);
                std::cout << "Interface Name: " << name << std::endl;
                unsigned char* mac = (unsigned char*)LLADDR(sdl);
                printf("MAC Address: %02x:%02x:%02x:%02x:%02x:%02x\n",
                       mac[0], mac[1], mac[2], mac[3], mac[4], mac[5]);
            }
        }
        ifa = ifa->ifa_next;
    }

    freeifaddrs(ifaList);

    return 0;
}
