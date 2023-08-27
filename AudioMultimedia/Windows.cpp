#include <iostream>
#include <Windows.h>
#include <dsound.h>

int main() {
    CoInitialize(nullptr);
    IDirectSound8* pDSound;
    DirectSoundCreate8(nullptr, &pDSound, nullptr);
    pDSound->SetCooperativeLevel(GetDesktopWindow(), DSSCL_NORMAL);
    IDirectSoundBuffer* pDSBuffer;
    pDSound->CreateSoundBuffer(/* buffer description */, &pDSBuffer, nullptr);
    pDSBuffer->Play(0, 0, 0);
    pDSBuffer->Release();
    pDSound->Release();
    CoUninitialize();
    return 0;
}
