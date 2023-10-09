#include <iostream>
#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>

int main() {
    CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);

    IMFAttributes *pAttributes = nullptr;
    IMFActivate** ppDevices = nullptr;
    UINT32 count = 0;

    HRESULT hr = MFCreateAttributes(&pAttributes, 1);
    if (SUCCEEDED(hr)) {
        hr = pAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_CAMERA);
    }

    if (SUCCEEDED(hr)) {
        hr = MFEnumDeviceSources(pAttributes, &ppDevices, &count);
    }

    if (SUCCEEDED(hr)) {
        std::cout << "Available Cameras:" << std::endl;
        for (UINT32 i = 0; i < count; i++) {
            LPWSTR name;
            ppDevices[i]->GetAllocatedString(MF_DEVSOURCE_ATTRIBUTE_FRIENDLY_NAME, &name, nullptr);
            wprintf(L"Camera %d: %s\n", i + 1, name);
            CoTaskMemFree(name);
        }
    }

    if (ppDevices) {
        for (UINT32 i = 0; i < count; i++) {
            ppDevices[i]->Release();
        }
        CoTaskMemFree(ppDevices);
    }

    if (pAttributes) {
        pAttributes->Release();
    }

    CoUninitialize();
    return 0;
}
