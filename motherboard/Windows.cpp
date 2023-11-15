#include <iostream>
#include <Windows.h>
#include <intrin.h>

void printMotherboardInfo() {
    //Windows Management Instrumentation (WMI) to query motherboard information
    const char* query = "SELECT * FROM Win32_BaseBoard";

    IEnumWbemClassObject* enumerator = nullptr;
    IWbemClassObject* object = nullptr;

    if (CoInitializeEx(0, COINIT_MULTITHREADED) == S_OK &&
        CoInitializeSecurity(nullptr, -1, nullptr, nullptr, RPC_C_AUTHN_LEVEL_DEFAULT, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE, nullptr) == S_OK) {

        if (CoCreateInstance(CLSID_WbemLocator, 0, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID*)&locator) == S_OK &&
            locator->ConnectServer(L"ROOT\\CIMV2", nullptr, nullptr, 0, nullptr, 0, 0, &service) == S_OK &&
            CoSetProxyBlanket(service, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, nullptr, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE) == S_OK &&
            service->ExecQuery(L"WQL", query, WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, nullptr, &enumerator) == S_OK) {

            ULONG uReturned;
            while (enumerator->Next(WBEM_INFINITE, 1, &object, &uReturned) == S_OK) {
                VARIANT var;
                if (object->Get(L"Manufacturer", 0, &var, 0, 0) == S_OK) {
                    std::wcout << L"Manufacturer: " << var.bstrVal << std::endl;
                    VariantClear(&var);
                }
                if (object->Get(L"Product", 0, &var, 0, 0) == S_OK) {
                    std::wcout << L"Product: " << var.bstrVal << std::endl;
                    VariantClear(&var);
                }
                object->Release();
            }
            enumerator->Release();
        }

        service->Release();
        locator->Release();
        CoUninitialize();
    }
}

int main() {
    printMotherboardInfo();
    return 0;
}
