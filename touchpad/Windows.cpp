//using <windows.devices.input.h>
#include <iostream>
#include <windows.devices.input.h>
#include <wrl.h>

using namespace Windows::Devices::Input;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;

int main() {
    RoInitializeWrapper initialize(RO_INIT_MULTITHREADED);
    if (FAILED(initialize)) {
        std::cerr << "Failed to initialize Windows Runtime" << std::endl;
        return 1;
    }

    ComPtr<MouseCapabilities> mouseCapabilities;
    HRESULT hr = GetActivationFactory(HStringReference(L"Windows.Devices.Input.MouseCapabilities").Get(), &mouseCapabilities);

    if (SUCCEEDED(hr)) {
        uint32_t numberOfButtons;
        hr = mouseCapabilities->get_NumberOfButtons(&numberOfButtons);

        if (SUCCEEDED(hr)) {
            std::wcout << L"Number of Mouse Buttons: " << numberOfButtons << std::endl;
        }
    }

    return 0;
}
