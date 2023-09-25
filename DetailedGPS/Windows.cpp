//will add or remove more functions in future

#include <iostream>
#include <winrt/Windows.Devices.Geolocation.h>

int main() {
    winrt::init_apartment();
    winrt::Windows::Devices::Geolocation::Geolocator geolocator;

    winrt::Windows::Devices::Geolocation::Geoposition pos = geolocator.GetGeopositionAsync().get();

    double latitude = pos.Coordinate().Latitude();
    double longitude = pos.Coordinate().Longitude();
    double altitude = pos.Coordinate().Altitude();

    std::cout << "Latitude: " << latitude << std::endl;
    std::cout << "Longitude: " << longitude << std::endl;
    std::cout << "Altitude: " << altitude << std::endl;

    return 0;
}
