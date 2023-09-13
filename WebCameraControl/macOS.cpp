#include <iostream>
#include <AVFoundation/AVFoundation.h>

int main() {
    @autoreleasepool {
        //Initialize the capture session
        AVCaptureSession* captureSession = [[AVCaptureSession alloc] init];

        //Find the default video device (webcam)
        AVCaptureDevice* videoDevice = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];

        if (videoDevice) {
            //Create a capture input for the video device
            NSError* error = nil;
            AVCaptureDeviceInput* videoInput = [AVCaptureDeviceInput deviceInputWithDevice:videoDevice error:&error];

            if (!error) {
                if ([captureSession canAddInput:videoInput]) {
                    [captureSession addInput:videoInput];
                }

                //Create a preview layer for displaying the webcam feed (optional)
                AVCaptureVideoPreviewLayer* previewLayer = [AVCaptureVideoPreviewLayer layerWithSession:captureSession];
                previewLayer.videoGravity = AVLayerVideoGravityResizeAspect;
                previewLayer.frame = CGRectMake(0, 0, 640, 480);

                //Add the preview layer to a view (optional)
                //[yourView.layer addSublayer:previewLayer];

                //Start the capture session
                [captureSession startRunning];

                //Control your webcam here
                std::cout << "Webcam initialized and capturing." << std::endl;
                //Add your webcam control code here

                //To stop capturing, call [captureSession stopRunning]

            } else {
                std::cerr << "Failed to create video input: " << error.localizedDescription.UTF8String << std::endl;
            }
        } else {
            std::cerr << "No video device found." << std::endl;
        }
    }

    return 0;
}
