#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct CPUInfo {
    std::string processor;
    //processor informations
    std::string vendor_id;
    std::string cpu_family;
    //add more fields as needed.
};

int main() {
    std::ifstream cpuinfo("/proc/cpuinfo");
    std::string line;
    std::vector<CPUInfo> cpus;

    CPUInfo current_cpu;
    while (std::getline(cpuinfo, line)) {
        if (line.empty()) {
            //newwww CPU entry
            cpus.push_back(current_cpu);
            current_cpu = CPUInfo();
        }
        else {
            if (line.find("processor") == 0) {
                current_cpu.processor = line.substr(line.find(":") + 2);
            }
            else if (line.find("vendor_id") == 0) {
                current_cpu.vendor_id = line.substr(line.find(":") + 2);
            }
            else if (line.find("cpu family") == 0) {
                current_cpu.cpu_family = line.substr(line.find(":") + 2);
            }
        }
    }

    for (const auto& cpu : cpus) {
        std::cout << "Processor: " << cpu.processor << std::endl;
        std::cout << "Vendor ID: " << cpu.vendor_id << std::endl;
        std::cout << "CPU Family: " << cpu.cpu_family << std::endl;.
        std::cout << std::endl;
    }

    return 0;
}
