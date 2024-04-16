#include <stdio.h>
//using asoundlib
#include <alsa/asoundlib.h>

int main() {
    int card = -1;
    snd_ctl_t* handle;

    while (snd_card_next(&card) == 0 && card >= 0) {
        char cardName[32];
        sprintf(cardName, "hw:%d", card);

        if (snd_ctl_open(&handle, cardName, 0) >= 0) {
            printf("Sound Card %d\n", card);
            printf("Card Name: %s\n", snd_ctl_card_info_get_name(handle));
            printf("Card ID: %s\n", snd_ctl_card_info_get_id(handle));
            printf("Card Driver: %s\n", snd_ctl_card_info_get_driver(handle));
            snd_ctl_close(handle);
        }
    }

    return 0;
}
