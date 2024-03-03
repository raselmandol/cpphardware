#include <iostream>
#include <windows.h>
#include <dxgi.h>

int main() {
    IDXGIFactory* pFactory;
    HRESULT hr = CreateDXGIFactory(__uuidof(IDXGIFactory), (void**)&pFactory);

    if (SUCCEEDED(hr)) {
        IDXGIAdapter* pAdapter;
        if (pFactory->EnumAdapters(0, &pAdapter) == S_OK) {
            DXGI_ADAPTER_DESC adapterDesc;
            if (SUCCEEDED(pAdapter->GetDesc(&adapterDesc))) {
                //using adapt_description
                std::wcout << L"GPU Description: " << adapterDesc.Description << std::endl;
                std::wcout << L"GPU Vendor ID: " << adapterDesc.VendorId << std::endl;
                //more GPU information in adapterDesc-->possible

                pAdapter->Release();
            }
        }

        pFactory->Release();
    }

    return 0;
}
