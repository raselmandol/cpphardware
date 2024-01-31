#include <iostream>
#import <LocalAuthentication/LocalAuthentication.h>

int main() {
    LAContext* context = [[LAContext alloc] init];
    NSError* error = nil;
    
    if ([context canEvaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometrics error:&error]) {
        [context evaluatePolicy:LAPolicyDeviceOwnerAuthenticationWithBiometrics
                localizedReason:@"Authenticate using biometrics"
                          reply:^(BOOL success, NSError* error) {
            if (success) {
                //Biometric authentication successful
            } else {
                //Biometric authentication failed or was canceled
                //controll here
            }
        }];
    } else {
        //Biometrics not available on this device
    }

    return 0;
}
