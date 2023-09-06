#include <iostream>
#include <windows.devices.bluetooth.h>
#include <wrl.h>

using namespace Windows::Devices::Bluetooth;
using namespace Windows::Foundation;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

int main() {
    RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
    if (FAILED(initialize)) {
        std::cerr << "Failed to initialize Windows Runtime" << std::endl;
        return 1;
    }

    ComPtr<BluetoothAdapter> adapter;
    HRESULT hr = BluetoothAdapter::FromBluetoothAddressAsync(0).Get()->get_DefaultAsync(&adapter);

    if (SUCCEEDED(hr)) {
        ComPtr<IBluetoothDevice> device;
        auto result = adapter->DeviceInformation->FindAllAsync().Get();
        for (const auto& info : result) {
            hr = BluetoothDevice::FromIdAsync(info->Id, &device).Get();
            if (SUCCEEDED(hr)) {
                hstring name;
                hr = device->get_Name(name.GetAddressOf());
                if (SUCCEEDED(hr)) {
                    std::wcout << L"Device Name: " << name.c_str() << std::endl;
                    //Print other Bluetooth device details as needed
                }
            }
        }
    }

    return 0;
}
