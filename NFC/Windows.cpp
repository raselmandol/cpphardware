#include <windows.h>
#include <winnfc.h>

int main() {
    NfcInitialize(NULL);
    DWORD deviceCount = 0;
    if (NfcGetDeviceCount(&deviceCount) == ERROR_SUCCESS) {
        for (DWORD i = 0; i < deviceCount; i++) {
            NfcDeviceHandle hDevice;
            if (NfcOpenDevice(i, &hDevice) == ERROR_SUCCESS) {
                //Get device details and interact with the NFC device
                //For example, you can read NFC tags or send commands
                //Close the device when done: NfcCloseDevice(hDevice);
            }
        }
    }
    
    NfcUninitialize();
    return 0;
}
