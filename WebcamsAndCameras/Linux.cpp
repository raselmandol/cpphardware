#include <iostream>
#include <fcntl.h>
#include <linux/videodev2.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
    const char* deviceName = "/dev/video0";
    int fd = open(deviceName, O_RDWR);
    if (fd == -1) {
        std::cerr << "Failed to open device." << std::endl;
        return 1;
    }

    struct v4l2_capability caps;
    if (ioctl(fd, VIDIOC_QUERYCAP, &caps) == -1) {
        std::cerr << "Failed to query capabilities." << std::endl;
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
