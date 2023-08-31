#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <chrono>
#include <thread>

#ifdef _WIN32 //Windows
#include <windows.h>
#else //Linux and macOS
#include <unistd.h>
#endif

#ifdef _WIN32 //Windows
const std::string serialPort = "COM3"; //Change to your serial port
#else //Linux and macOS
const std::string serialPort = "/dev/ttyUSB0"; //Change to your serial port
#endif

int main() {
#ifdef _WIN32 //Windows
    HANDLE hSerial;
    hSerial = CreateFileA(serialPort.c_str(), GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
    if (hSerial == INVALID_HANDLE_VALUE) {
        std::cerr << "Error opening serial port." << std::endl;
        return 1;
    }
    DCB dcbSerialParams = { 0 };
    dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
    if (!GetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "Error getting serial port state." << std::endl;
        CloseHandle(hSerial);
        return 1;
    }
    dcbSerialParams.BaudRate = CBR_9600; //Change to your baud rate
    dcbSerialParams.ByteSize = 8;
    dcbSerialParams.StopBits = ONESTOPBIT;
    dcbSerialParams.Parity = NOPARITY;
    if (!SetCommState(hSerial, &dcbSerialParams)) {
        std::cerr << "Error setting serial port state." << std::endl;
        CloseHandle(hSerial);
        return 1;
    }
#else //Linux and macOS
    int hSerial = open(serialPort.c_str(), O_RDWR | O_NOCTTY);
    if (hSerial == -1) {
        std::cerr << "Error opening serial port." << std::endl;
        return 1;
    }
    struct termios serialParams;
    tcgetattr(hSerial, &serialParams);
    serialParams.c_cflag = B9600; //Change to your baud rate
    serialParams.c_cflag |= CS8;
    serialParams.c_cflag |= CREAD;
    serialParams.c_cflag |= CLOCAL;
    serialParams.c_iflag = 0;
    serialParams.c_oflag = 0;
    serialParams.c_lflag = 0;
    tcsetattr(hSerial, TCSANOW, &serialParams);
#endif

    char data[256];
    while (true) {
        memset(data, 0, sizeof(data));
#ifdef _WIN32 //Windows
        DWORD bytesRead;
        if (!ReadFile(hSerial, data, sizeof(data), &bytesRead, NULL)) {
            std::cerr << "Error reading from serial port." << std::endl;
            CloseHandle(hSerial);
            return 1;
        }
#else //Linux and macOS
        ssize_t bytesRead = read(hSerial, data, sizeof(data));
        if (bytesRead == -1) {
            std::cerr << "Error reading from serial port." << std::endl;
            close(hSerial);
            return 1;
        }
#endif

        //Process and parse NMEA sentences here
        std::string nmeaSentence(data, bytesRead);
        std::cout << "Received: " << nmeaSentence;

#ifdef _WIN32 //Windows
        Sleep(1000); //Sleep for 1 second
#else //Linux and macOS
        sleep(1);    //Sleep for 1 second
#endif
    }

#ifdef _WIN32 //Windows
    CloseHandle(hSerial);
#else //Linux and macOS
    close(hSerial);
#endif

    return 0;
}
