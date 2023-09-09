#include <stdio.h>
#include <alsa/asoundlib.h>

int main() {
    int card = -1;
    int err;

    while (1) {
        if (snd_card_next(&card) < 0 || card < 0) {
            break;
        }

        char cardName[64];
        sprintf(cardName, "hw:%d", card);

        snd_ctl_t* handle;
        if (snd_ctl_open(&handle, cardName, 0) >= 0) {
            printf("Sound Card: %s\n", snd_ctl_card_info_get_name(handle));
            snd_ctl_close(handle);
        }
    }

    return 0;
}
