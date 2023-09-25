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

            std::cout << "Latitude: " << latitude << std::endl;
            std::cout << "Longitude: " << longitude << std::endl;
            std::cout << "Altitude: " << altitude << std::endl;
        }
    }
    gps_close(&gpsdata);
    return 0;
}
