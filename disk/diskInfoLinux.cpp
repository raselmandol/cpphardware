#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

struct DiskInfo {
    std::string name;
    unsigned long long size;
};

std::vector<DiskInfo> getDiskInfo() {
    std::vector<DiskInfo> disks;
    
    std::ifstream partitions("/proc/partitions");
    std::string line;
    std::getline(partitions, line);
    
    while (std::getline(partitions, line)) {
        std::istringstream iss(line);
        int major, minor, blocks;
        std::string name;
        iss >> major >> minor >> blocks >> name;
        if (name.find("sd") == 0 || name.find("hd") == 0) {
            DiskInfo disk;
            disk.name = "/dev/" + name;
            disk.size = static_cast<unsigned long long>(blocks) * 1024;
            disks.push_back(disk);
        }
    }
    
    return disks;
}

int main() {
    std::vector<DiskInfo> disks = getDiskInfo();
    for (const DiskInfo& disk : disks) {
        std::cout << "Disk Name: " << disk.name << std::endl;
        std::cout << "Disk Size: " << disk.size / (1024 * 1024 * 1024) << " GB" << std::endl;
        std::cout << std::endl;
    }
    
    return 0;
}
