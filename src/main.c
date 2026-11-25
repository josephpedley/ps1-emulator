#include "bios.h"
#include "cpu.h"
#include "interconnect.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main()
{
    static struct CPU cpu;
    static struct interconnect interconnect;

    if (!load_bios_image(&interconnect.bios, "ps_files/SCPH1001.BIN")) // TODO pass as cmdline arg
    {
        return 1;
    }

    cpu_reset(&cpu, &interconnect);

    while (1)
    {
        cpu_step(&cpu);
    }
}
