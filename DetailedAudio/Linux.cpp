#include <iostream>
#include <alsa/asoundlib.h>

int main() {
    snd_ctl_t *handle;
    snd_ctl_card_info_t *info;
    int card = -1;

    while (snd_card_next(&card) >= 0 && card >= 0) {
        char cardName[32];
        sprintf(cardName, "hw:%d", card);

        if (snd_ctl_open(&handle, cardName, 0) < 0) {
            continue;
        }

        snd_ctl_card_info_alloca(&info);
        snd_ctl_card_info(handle, info);
        //printing infos

        std::cout << "Card " << card << ": " << snd_ctl_card_info_get_name(info) << std::endl;
        snd_ctl_close(handle);
    }

    return 0;
}
