#include <iostream>
#include <AVFoundation/AVFoundation.h>

int main() {
    @autoreleasepool {
        AVCaptureSession* captureSession = [[AVCaptureSession alloc] init];
        AVCaptureDevice* camera = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];

        NSError* error = nil;
        AVCaptureDeviceInput* cameraInput = [AVCaptureDeviceInput deviceInputWithDevice:camera error:&error];
        if (error) {
            NSLog(@"Error: %@", error);
            return 1;
        }

        [captureSession addInput:cameraInput];
        AVCaptureVideoDataOutput* videoOutput = [[AVCaptureVideoDataOutput alloc] init];
        [captureSession addOutput:videoOutput];
        [captureSession startRunning];

        [captureSession stopRunning];
    }

    return 0;
}
