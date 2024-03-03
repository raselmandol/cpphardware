#include <iostream>
#include <cstdio>
//too short? huh? 
int main() {
    //directly_open_trig
    FILE* fp = popen("lspci -v -s $(lspci | grep ' VGA ' | cut -d' ' -f1)", "r");
    if (fp) {
        char buffer[256];
        while (fgets(buffer, sizeof(buffer), fp)) {
            std::cout << buffer;
        }
        pclose(fp);
    }
    return 0;
}
