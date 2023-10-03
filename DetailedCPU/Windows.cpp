#include <iostream>
#include <windows.h>
#include <comdef.h>
#include <Wbemidl.h>

#pragma comment(lib, "wbemuuid.lib")

int main() {
    HRESULT hres;

    hres = CoInitializeSecurity(
        nullptr,                    //Security descriptor
        -1,                         //COM authentication
        nullptr,                    //Authentication services
        nullptr,                    //Reserved
        RPC_C_AUTHN_LEVEL_DEFAULT,  //Default authentication
        RPC_C_IMP_LEVEL_IMPERSONATE,//Default impersonation
        nullptr,                    //Authentication info
        EOAC_NONE,                  //Additional capabilities
        nullptr                     //Reserved
    );

    if (FAILED(hres)) {
        std::cerr << "Failed to initialize COM security" << std::endl;
        return 1;
    }

    hres = CoInitializeEx(0, COINIT_MULTITHREADED);
    if (FAILED(hres)) {
        std::cerr << "Failed to initialize COM" << std::endl;
        CoUninitialize();
        return 1;
    }

    IWbemLocator* pLoc = nullptr;
    hres = CoCreateInstance(
        CLSID_WbemLocator,           //CLSID associated with the WbemLocator
        0,                          //Reserved
        CLSCTX_INPROC_SERVER,       //Context for running executable code
        IID_IWbemLocator,           //Interface ID
        (LPVOID*)&pLoc              //Interface pointer
    );

    if (FAILED(hres)) {
        std::cerr << "Failed to create IWbemLocator object" << std::endl;
        CoUninitialize();
        return 1;
    }

    IWbemServices* pSvc = nullptr;
    hres = pLoc->ConnectServer(
        _bstr_t(L"ROOT\\CIMV2"),    //Namespace
        nullptr,                    //User name
        nullptr,                    //Password
        0,                          //Locale
        nullptr,                    //Security flags
        0,                          //Authority
        0,                          //Context object
        &pSvc                       //IWbemServices proxy
    );

    if (FAILED(hres)) {
        std::cerr << "Failed to connect to WMI" << std::endl;
        pLoc->Release();
        CoUninitialize();
        return 1;
    }


    hres = CoSetProxyBlanket(
        pSvc,                       //IWbemServices proxy
        RPC_C_AUTHN_WINNT,          //Authentication service
        RPC_C_AUTHZ_NONE,           //Authorization service
        nullptr,                    //Server principal name
        RPC_C_AUTHN_LEVEL_CALL,     //Authentication level
        RPC_C_IMP_LEVEL_IMPERSONATE,//Impersonation level
        nullptr,                    //Authentication info
        EOAC_NONE                   //Additional capabilities
    );

    if (FAILED(hres)) {
        std::cerr << "Failed to set proxy blanket" << std::endl;
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return 1;
    }
    IEnumWbemClassObject* pEnumerator = nullptr;
    hres = pSvc->ExecQuery(
        _bstr_t("WQL"),
        _bstr_t("SELECT * FROM Win32_Processor"),
        WBEM_FLAG_FORWARD_ONLY | WBEM_FLAG_RETURN_IMMEDIATELY,
        nullptr,
        &pEnumerator
    );

    if (FAILED(hres)) {
        std::cerr << "Failed to execute WMI query" << std::endl;
        pSvc->Release();
        pLoc->Release();
        CoUninitialize();
        return 1;
    }

    IWbemClassObject* pclsObj = nullptr;
    ULONG uReturn = 0;

    while (pEnumerator) {
        HRESULT hr = pEnumerator->Next(WBEM_INFINITE, 1, &pclsObj, &uReturn);

        if (0 == uReturn) {
            break;
        }

        VARIANT vtProp;
        hr = pclsObj->Get(L"Name", 0, &vtProp, 0, 0);
        if (SUCCEEDED(hr)) {
            std::wcout << L"CPU Name: " << vtProp.bstrVal << std::endl;
            VariantClear(&vtProp);
        }

        hr = pclsObj->Get(L"Manufacturer", 0, &vtProp, 0, 0);
        if (SUCCEEDED(hr)) {
            std::wcout << L"Manufacturer: " << vtProp.bstrVal << std::endl;
            VariantClear(&vtProp);
        }

        hr = pclsObj->Get(L"NumberOfCores", 0, &vtProp, 0, 0);
        if (SUCCEEDED(hr)) {
            std::wcout << L"Number of Cores: " << vtProp.ulVal << std::endl;
            VariantClear(&vtProp);
        }

        hr = pclsObj->Get(L"NumberOfLogicalProcessors", 0, &vtProp, 0, 0);
        if (SUCCEEDED(hr)) {
            std::wcout << L"Number of Logical Processors: " << vtProp.ulVal << std::endl;
            VariantClear(&vtProp);
        }

        pclsObj->Release();
    }

    pSvc->Release();
    pLoc->Release();
    pEnumerator->Release();
    CoUninitialize();

    return 0;
}
