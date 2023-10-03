#include <iostream>
#include <cstdlib>

int main() {
    //running 'sysctl' to get CPU details
    //this one I got as the largest ref of hardware with c++
    //Jokes23
    std::system("sysctl -a | grep machdep.cpu");

    return 0;
}
