#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

#include "bios.h"


int main()
{
    struct Bios bios;

    if (!load_bios_image(&bios, "ps_files/SCPH1001.BIN"))
    {
        return 1;
    }

    uint32_t first_word = load_bios_word(&bios, 0);
}
