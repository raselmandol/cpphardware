#include <iostream>
#include <windows.h>
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>

int main() {
    CoInitialize(nullptr);
    MFStartup(MF_VERSION);

    IMFMediaSource* pSource = nullptr;
    IMFAttributes* pAttributes = nullptr;
    IMFActivate** ppDevices = nullptr;

    MFCreateAttributes(&pAttributes, 1);
    pAttributes->SetGUID(MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE, MF_DEVSOURCE_ATTRIBUTE_SOURCE_TYPE_VIDCAP_GUID);

    UINT32 count = 0;
    MFEnumDeviceSources(pAttributes, &ppDevices, &count);

    if (count > 0) {
        ppDevices[0]->ActivateObject(IID_PPV_ARGS(&pSource));
        ppDevices[0]->Release();
        pSource->Release();
    }

    MFShutdown();
    CoUninitialize();

    return 0;
}
