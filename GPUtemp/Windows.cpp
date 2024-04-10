#include <iostream>
#include <Windows.h>
#include <Ntddvdeo.h>

int main() {
    //assuming a single GPU
    ADAPTER_INFO adapterInfo;
    //using signalInfo
    DISPLAYCONFIG_VIDEO_SIGNAL_INFO signalInfo;

    memset(&adapterInfo, 0, sizeof(adapterInfo));
    adapterInfo.Size = sizeof(adapterInfo);
    memset(&signalInfo, 0, sizeof(signalInfo));
    signalInfo.sizeOfStruct = sizeof(DISPLAYCONFIG_VIDEO_SIGNAL_INFO);

    if (EnumDisplayDevices(nullptr, 0, &adapterInfo, 0)) {
        if (GetDisplayConfigBufferSizes(QDC_DATABASE_CURRENT, &numPathArrayElements, &numModeInfoArrayElements) == ERROR_SUCCESS) {
            auto pathArray = new DISPLAYCONFIG_PATH_INFO[numPathArrayElements];
            auto modeInfoArray = new DISPLAYCONFIG_MODE_INFO[numModeInfoArrayElements];

            if (QueryDisplayConfig(QDC_DATABASE_CURRENT, &numPathArrayElements, pathArray, &numModeInfoArrayElements, modeInfoArray, nullptr) == ERROR_SUCCESS) {
                for (UINT32 i = 0; i < numPathArrayElements; ++i) {
                    if (pathArray[i].sourceInfo.adapterId.HighPart == adapterInfo.AdapterId.HighPart &&
                        pathArray[i].sourceInfo.adapterId.LowPart == adapterInfo.AdapterId.LowPart) {
                        signalInfo = modeInfoArray[pathArray[i].sourceInfo.modeInfoIdx].targetVideoSignalInfo;
                        break;
                    }
                }
            }
            delete[] pathArray;
            delete[] modeInfoArray;
        }
    }

    std::cout << "GPU Temperature: " << signalInfo.scanLineStartTime / 1000.0 << " degrees Celsius" << std::endl;

    return 0;
}
