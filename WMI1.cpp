#include <iostream>
#include <comdef.h>
#include <Wbemidl.h>

#pragma comment(lib, "wbemuuid.lib")

void GetSystemInfo() {
    CoInitializeEx(0, COINIT_MULTITHREADED);
    CoInitializeSecurity(nullptr, -1, nullptr, nullptr, RPC_C_AUTHN_LEVEL_DEFAULT,
                         RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE, nullptr);

    IWbemLocator* pLoc = nullptr;
    IWbemServices* pSvc = nullptr;

    HRESULT hres = CoCreateInstance(CLSID_WbemLocator, nullptr, CLSCTX_INPROC_SERVER,
                                   IID_IWbemLocator, reinterpret_cast<LPVOID*>(&pLoc));

    if (SUCCEEDED(hres)) {
        hres = pLoc->ConnectServer(_bstr_t(L"ROOT\\CIMv2"), nullptr, nullptr, 0, nullptr, 0, 0, &pSvc);

        if (SUCCEEDED(hres)) {
            hres = CoSetProxyBlanket(pSvc, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, nullptr,
                                      RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE);

            if (SUCCEEDED(hres)) {
                IEnumWbemClassObject* pEnumerator = nullptr;
                hres = pSvc->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM Win32_ComputerSystem"), WBEM_FLAG_FORWARD_ONLY, nullptr, &pEnumerator);

                if (SUCCEEDED(hres)) {
                    IWbemClassObject* pclsObj = nullptr;
                    ULONG uReturn = 0;

                    while (pEnumerator) {
                        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

                        if (0 == uReturn) break;

                        VARIANT vtProp;
                        hr = pclsObj->Get(L"Manufacturer", 0, &vtProp, 0, 0);
                        wprintf(L"Manufacturer: %s\n", vtProp.bstrVal);
                        VariantClear(&vtProp);

                        hr = pclsObj->Get(L"Model", 0, &vtProp, 0, 0);
                        wprintf(L"Model: %s\n", vtProp.bstrVal);
                        VariantClear(&vtProp);

                        pclsObj->Release();
                    }

                    pEnumerator->Release();
                }
                //additional queries for processor and memory information
                hres = pSvc->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM Win32_Processor"), WBEM_FLAG_FORWARD_ONLY, nullptr, &pEnumerator);

                if (SUCCEEDED(hres)) {
                    IWbemClassObject* pclsObj = nullptr;
                    ULONG uReturn = 0;

                    while (pEnumerator) {
                        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

                        if (0 == uReturn) break;

                        VARIANT vtProp;
                        hr = pclsObj->Get(L"Name", 0, &vtProp, 0, 0);
                        //P name, Release object
                        wprintf(L"Processor Name: %s\n", vtProp.bstrVal);
                        VariantClear(&vtProp);

                        pclsObj->Release();
                    }

                    pEnumerator->Release();
                }

                hres = pSvc->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM Win32_PhysicalMemory"), WBEM_FLAG_FORWARD_ONLY, nullptr, &pEnumerator);

                if (SUCCEEDED(hres)) {
                    IWbemClassObject* pclsObj = nullptr;
                    ULONG uReturn = 0;

                    while (pEnumerator) {
                        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

                        if (0 == uReturn) break;

                        VARIANT vtProp;
                        hr = pclsObj->Get(L"Capacity", 0, &vtProp, 0, 0);
                        wprintf(L"Physical Memory Capacity: %lld bytes\n", vtProp.llVal);
                        VariantClear(&vtProp);

                        pclsObj->Release();
                    }

                    pEnumerator->Release();
                }
            }

            pSvc->Release();
        }

        pLoc->Release();
        CoUninitialize();
    }
}

int main() {
    GetSystemInfo();

    return 0;
}
