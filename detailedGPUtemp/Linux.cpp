#include <iostream>
#include <cstdio>

int main() {
    FILE* pipe = popen("nvidia-smi --query-gpu=temperature.gpu --format=csv,noheader,nounits", "r");
    if (pipe) {
        char buffer[128];
        if (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            int temperature = std::stoi(buffer);
            std::cout << "GPU Temperature: " << temperature << "°C" << std::endl;
        }
        pclose(pipe);
    }

    return 0;
}
