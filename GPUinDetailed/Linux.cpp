#include <iostream>
#include <cstdio>
//too short? huh? 
int main() {
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
