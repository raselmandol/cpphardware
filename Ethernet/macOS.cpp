#include <SystemConfiguration/SystemConfiguration.h>
#include <stdio.h>

int main() {
    //check mannually 
    SCNetworkReachabilityRef reachability = SCNetworkReachabilityCreateWithName(kCFAllocatorDefault, "www.apple.com");

    if (reachability) {
        SCNetworkConnectionFlags flags;
        if (SCNetworkReachabilityGetFlags(reachability, &flags)) {
            if ((flags & kSCNetworkFlagsReachable) && !(flags & kSCNetworkFlagsConnectionRequired)) {
                printf("Connected to a network (possibly Ethernet).\n");
            } else {
                printf("Not connected to a network.\n");
            }
        }

        CFRelease(reachability);
    }

    return 0;
}
