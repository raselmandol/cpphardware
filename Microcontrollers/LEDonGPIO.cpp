//for Windows
//Simple C++ program to toggle an LED connected to a GPIO pin
//This example demonstrates how to interact with GPIO pins on a microcontroller

#ifdef _WIN32
#include <windows.h>
#else 
#include <unistd.h>
#endif

int main() {
    //set  the pin value accd to the output ledPin
    const int ledPin = 13;
    pinMode(ledPin, OUTPUT);

    while (true) {
        digitalWrite(ledPin, HIGH);  
        delay(1000);                
        digitalWrite(ledPin, LOW);  
        delay(1000);               

#ifdef _WIN32
        //make some delay?
        //delay()--> 1...2...3...
        Sleep(2000);
#else
        sleep(2);   
#endif
    }

    return 0;
}
