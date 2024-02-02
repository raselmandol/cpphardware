#include <CoreBluetooth/CoreBluetooth.h>
#include <stdio.h>

void scanCallback(CBPeripheral* peripheral, NSDictionary* advertisementData, int RSSI, bool advertising) {
    if (peripheral.name != nil) {
        printf("Device Name: %s\n", peripheral.name.UTF8String);
        //Printing other Bluetooth device details as needed
    }
}

int main() {
    @autoreleasepool {
        CBCentralManager* centralManager = [[CBCentralManager alloc] initWithDelegate:nil queue:nil];
        [centralManager scanForPeripheralsWithServices:nil options:nil];
        sleep(5); //Adjusting the scan duration as needed
        [centralManager stopScan];
    }
    return 0;
}
