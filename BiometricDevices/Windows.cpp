#include <windows.h>
#include <winbio.h>

int main() {
    HRESULT hr = S_OK;
    WINBIO_SESSION_HANDLE sessionHandle = NULL;
    
    hr = WinBioOpenSession(WINBIO_TYPE_FINGERPRINT, WINBIO_POOL_SYSTEM, WINBIO_FLAG_RAW, NULL, 0, 0, &sessionHandle);
    if (FAILED(hr)) {
        //Handling error
    }

    //Enumerating biometric units, capture data, etc.

    WinBioCloseSession(sessionHandle);
    return 0;
}
