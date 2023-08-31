#include <iostream>
#include <windows.h>

const std::string serialPort = "COM3";

int main() {
    HANDLE hSerial;
    hSerial = CreateFileA(serialPort.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cerr << "Error opening serial port." << std::endl;
        return 1;
    }
    
    while (true) {
        
        Sleep(1000);
    }

    CloseHandle(hSerial);
    return 0;
}
