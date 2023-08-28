#include <iostream>
#include <windows.devices.bluetooth.h>
#include <wrl.h>

using namespace Microsoft::WRL;
using namespace Windows::Devices::Bluetooth;
using namespace Windows::Devices::Enumeration;

int main() {
    HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (SUCCEEDED(hr)) {
        ComPtr<DeviceInformationCollection> devices;
        DeviceInformation::FindAllAsync(BluetoothDevice::GetDeviceSelector(), &devices);

        for (unsigned int i = 0; i < devices->Size; ++i) {
            ComPtr<IDeviceInformation> deviceInfo;
            devices->GetAt(i, &deviceInfo);

            HSTRING name;
            deviceInfo->get_Name(&name);

            const wchar_t* nameBuffer = WindowsGetStringRawBuffer(name, nullptr);
            std::wcout << "Bluetooth Device Name: " << nameBuffer << std::endl;

            WindowsDeleteString(name);
        }
        CoUninitialize();
    }
    return 0;
}
