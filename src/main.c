#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>

#include "bios.h"
#include "interconnect.h"

int main()
{
    struct interconnect interconnect;

    if (!load_bios_image(&interconnect.bios, "ps_files/SCPH1001.BIN"))
    {
        return 1;
    }

    uint32_t first_word = load_bios_word(&interconnect.bios, 0);
    uint32_t second_word = load32(&interconnect, 0xbfc00004);
}
