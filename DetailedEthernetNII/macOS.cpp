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
/*
_________MANDOL_0101_RASEL___
_________MANDOL_0101_RASEL___
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_________MANDOL_0101_RASEL___
_________MANDOL_0101_RASEL___

_____010101_____________________
_0101010101010__________________
010101010101010_________________
01010101010101011_______________
01010101010101010_______________
01010101010101010101010101______
01010101010101010101010101010___
0101010100101010101010101010101_
01010101010101010101010101010101
010101010101010101010101010__01_
01010101010101010100101010101___
01010100101010010101010101______
01010101010101010101010_________
1010101010101010101_____________
01010101010101__________________
101010101_______________________
010101__________________________
10______________________________
*/
