#include <iostream>
#include <CoreBluetooth/CoreBluetooth.h>

int main() {
    @autoreleasepool {
        CBCentralManager* centralManager = [[CBCentralManager alloc] initWithDelegate:nil queue:nil];
        [centralManager scanForPeripheralsWithServices:nil options:nil];
        sleep(5);

        //Bluetooth Peripheral Name
        NSArray* peripherals = [centralManager retrievePeripheralsWithIdentifiers:@[]];
        for (CBPeripheral* peripheral in peripherals) {
            NSLog(@"Bluetooth Peripheral Name: %@", peripheral.name);
        }
    }
    return 0;
}
