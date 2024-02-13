#include <iostream>
#include <windows.networking.connectivity.h>
#include <wrl.h>

using namespace Windows::Networking::Connectivity;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

int main() {
    RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
    if (FAILED(initialize)) {
        std::cerr << "Failed to initialize Windows Runtime" << std::endl;
        return 1;
    }

    //netInfo
    NetworkInformation::GetInternetConnectionProfile();

    if (NetworkInformation::GetInternetConnectionProfile()) {
        std::cout << "Connected to a network (possibly Ethernet)." << std::endl;
    } else {
        std::cout << "Not connected to a network." << std::endl;
    }

    return 0;
}
