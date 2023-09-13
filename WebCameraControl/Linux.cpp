#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    //Open the default camera (usually /dev/video0)
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Failed to open the webcam." << std::endl;
        return -1;
    }

    //Set webcam parameters (optional)
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, 480);

    while (true) {
        cv::Mat frame;
        cap >> frame; // Capture a frame

        if (frame.empty()) {
            break;
        }

        //Process and display the frame (add your code here)

        cv::imshow("Webcam", frame);

        if (cv::waitKey(30) == 27) {
            break; //Exit on ESC key press
        }
    }

    cap.release();
    cv::destroyAllWindows();

    return 0;
}
