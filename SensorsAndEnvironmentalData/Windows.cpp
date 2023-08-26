#include <iostream>
#include <Windows.h>
#include <sensorsapi.h>

int main() {
    CoInitialize(NULL);

    ISensorManager* pSensorManager;
    CoCreateInstance(CLSID_SensorManager, NULL, CLSCTX_INPROC_SERVER, IID_PPV_ARGS(&pSensorManager));

    ISensorCollection* pSensors;
    pSensorManager->GetSensorsByType(SENSOR_TYPE_LIGHT, &pSensors);

    ULONG count;
    pSensors->GetCount(&count);

    for (ULONG i = 0; i < count; ++i) {
        ISensor* pSensor;
        pSensors->GetAt(i, &pSensor);

        PROPVARIANT value;
        PropVariantInit(&value);
        pSensor->GetDataField(SENSOR_DATA_TYPE_LIGHT_LEVEL_LUX, &value);

        if (value.vt == VT_R4) {
            std::cout << "Light Level: " << value.fltVal << " lux" << std::endl;
        }

        PropVariantClear(&value);
        pSensor->Release();
    }

    pSensors->Release();
    pSensorManager->Release();
    CoUninitialize();

    return 0;
}
