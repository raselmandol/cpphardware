#include <iostream>
#include <windows.h>
#include <comdef.h>
#include <wbemidl.h>

int main() {
    CoInitialize(nullptr);
    IWbemLocator* pLoc = nullptr;
    IWbemServices* pSvc = nullptr;
    HRESULT hres = CoCreateInstance(CLSID_WbemLocator, nullptr, CLSCTX_INPROC_SERVER, IID_IWbemLocator, (LPVOID*)&pLoc);
    if (SUCCEEDED(hres)) {
        hres = pLoc->ConnectServer(_bstr_t(L"ROOT\\CIMV2"), nullptr, nullptr, nullptr, 0, nullptr, nullptr, &pSvc);
        if (SUCCEEDED(hres)) {
            hres = CoSetProxyBlanket(pSvc, RPC_C_AUTHN_WINNT, RPC_C_AUTHZ_NONE, nullptr, RPC_C_AUTHN_LEVEL_CALL, RPC_C_IMP_LEVEL_IMPERSONATE, nullptr, EOAC_NONE);
            if (SUCCEEDED(hres)) {
                IEnumWbemClassObject* pEnumerator = nullptr;
                hres = pSvc->ExecQuery(bstr_t("WQL"), bstr_t("SELECT * FROM Win32_TemperatureProbe"), WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY, nullptr, &pEnumerator);
                if (SUCCEEDED(hres)) {
                    IWbemClassObject* pclsObj = nullptr;
                    ULONG uReturn = 0;

                    while (pEnumerator) {
                        hres = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);
                        if (uReturn == 0) break;

                        VARIANT vtProp;
                        hres = pclsObj->Get(L"Name", 0, &vtProp, 0, 0);
                        if (SUCCEEDED(hres)) {
                            std::wcout << "Name : " << vtProp.bstrVal << std::endl;
                            VariantClear(&vtProp);
                        }
                        pclsObj->Release();
                    }
                    pEnumerator->Release();
                }
            }
        }
    }
    pSvc->Release();
    pLoc->Release();
    CoUninitialize();

    return 0;
}
