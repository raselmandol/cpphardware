#include <iostream>
#include <Winsock2.h>
#include <IPHlpApi.h>
#pragma comment(lib, "iphlpapi.lib")

int main() {
    PIP_ADAPTER_INFO pAdapterInfo;
    ULONG ulOutBufLen = sizeof(IP_ADAPTER_INFO);
    DWORD dwRetVal;

    pAdapterInfo = (IP_ADAPTER_INFO*)malloc(sizeof(IP_ADAPTER_INFO));
    if (pAdapterInfo == NULL) {
        std::cerr << "Memory allocation failed." << std::endl;
        return 1;
    }

    if (GetAdaptersInfo(pAdapterInfo, &ulOutBufLen) == ERROR_BUFFER_OVERFLOW) {
        free(pAdapterInfo);
        pAdapterInfo = (IP_ADAPTER_INFO*)malloc(ulOutBufLen);
        if (pAdapterInfo == NULL) {
            std::cerr << "Memory allocation failed." << std::endl;
            return 1;
        }
    }

    if ((dwRetVal = GetAdaptersInfo(pAdapterInfo, &ulOutBufLen)) == NO_ERROR) {
        IP_ADAPTER_INFO* pAdapter = pAdapterInfo;
        while (pAdapter) {
            std::cout << "Adapter Name: " << pAdapter->AdapterName << std::endl;
            std::cout << "Description: " << pAdapter->Description << std::endl;
            std::cout << "IP Address: " << pAdapter->IpAddressList.IpAddress.String << std::endl;

            pAdapter = pAdapter->Next;
        }
    } else {
        std::cerr << "GetAdaptersInfo failed with error: " << dwRetVal << std::endl;
    }

    if (pAdapterInfo)
        free(pAdapterInfo);

    return 0;
}
