//using core NFC framework
#include <iostream>
#import <CoreNFC/CoreNFC.h>

int main() {
    @autoreleasepool {
        NFCNDEFReaderSession* session = [[NFCNDEFReaderSession alloc] initWithDelegate:nil queue:dispatch_get_main_queue() invalidateAfterFirstRead:YES];

        [session beginSession];

        //Implement NFC delegate methods to handle NFC data and device details
        //For example, you can read NFC tags or send commands
    }

    return 0;
}
