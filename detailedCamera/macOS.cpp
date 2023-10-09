#include <iostream>
#include <AVFoundation/AVFoundation.h>

int main() {
    @autoreleasepool {
        NSArray *devices = [AVCaptureDevice devicesWithMediaType:AVMediaTypeVideo];
        
        if (devices.count == 0) {
            std::cerr << "No video capture devices found." << std::endl;
            return 1;
        }

        std::cout << "Available Cameras:" << std::endl;
        
        for (AVCaptureDevice *device in devices) {
            std::cout << "Device Name: " << device.localizedName.UTF8String << std::endl;
            std::cout << "Unique ID: " << device.uniqueID.UTF8String << std::endl;
            std::cout << "Model ID: " << device.modelID.UTF8String << std::endl;
            std::cout << "Media Type: " << [device mediaType].UTF8String << std::endl;
            std::cout << "Position: " << [device position].UTF8String << std::endl;
            std::cout << std::endl;
        }
    }

    return 0;
}
