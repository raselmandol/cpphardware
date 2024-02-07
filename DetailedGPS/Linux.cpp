#include <iostream>
#include <gps.h>

int main() {
    struct gps_data_t gpsdata;

    if (gps_open("localhost", "2947", &gpsdata) == -1) {
        std::cerr << "Error: gps_open failed" << std::endl;
        return 1;
    }
    while (gps_waiting(&gpsdata, 5000000)) {
        if (gps_read(&gpsdata) == -1) {
            std::cerr << "Error: gps_read failed" << std::endl;
            break;
        }
        if (gpsdata.status == STATUS_FIX) {
            double latitude = gpsdata.fix.latitude;
            double longitude = gpsdata.fix.longitude;
            double altitude = gpsdata.fix.altitude;

            //printing details
            std::cout << "Latitude: " << latitude << std::endl;
            std::cout << "Longitude: " << longitude << std::endl;
            std::cout << "Altitude: " << altitude << std::endl;
        }
    }
    gps_close(&gpsdata);
    return 0;
}
/*
_________MANDOL_0101_RASEL___
_________MANDOL_0101_RASEL___
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_____________0101010_________
_________MANDOL_0101_RASEL___
_________MANDOL_0101_RASEL___

_____010101_____________________
_0101010101010__________________
010101010101010_________________
01010101010101011_______________
01010101010101010_______________
01010101010101010101010101______
01010101010101010101010101010___
0101010100101010101010101010101_
01010101010101010101010101010101
010101010101010101010101010__01_
01010101010101010100101010101___
01010100101010010101010101______
01010101010101010101010_________
1010101010101010101_____________
01010101010101__________________
101010101_______________________
010101__________________________
10______________________________
*/
