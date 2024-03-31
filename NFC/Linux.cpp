//using libnfc
#include <iostream>
#include <nfc/nfc.h>

int main() {
    nfc_context* context;
    nfc_init(&context);

    //Open the first NFC device
    nfc_device* pnd = nfc_open(context, NULL);
    if (pnd != NULL) {
        //Configure and interact with the NFC device
        //For example, you can read NFC tags or send commands
        //close device handler
        nfc_close(pnd);
    }

    nfc_exit(context);
    return 0;
}
