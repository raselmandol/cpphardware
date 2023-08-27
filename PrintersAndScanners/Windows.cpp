#include <iostream>
#include <windows.devices.printers.h>
#include <wrl.h>

using namespace Microsoft::WRL;
using namespace Windows::Devices::Printers;

int main() {
    HRESULT hr = CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
    if (SUCCEEDED(hr)) {
        ComPtr<IPrinterExtensionContextCollection> printerContexts;
        hr = PrinterExtensionContext::GetForCurrentView(&printerContexts);
        if (SUCCEEDED(hr)) {
            ComPtr<IPrinterExtensionContext> printerContext;
            hr = printerContexts->GetAt(0, &printerContext);
            if (SUCCEEDED(hr)) {
                HSTRING printerName;
                hr = printerContext->get_PrinterName(&printerName);
                if (SUCCEEDED(hr)) {
                    const wchar_t* printerNameBuffer = WindowsGetStringRawBuffer(printerName, nullptr);
                    std::wcout << "Printer Name: " << printerNameBuffer << std::endl;
                    WindowsDeleteString(printerName);
                }
            }
        }
        CoUninitialize();
    }
    return 0;
}
