#include "interconnect.h"

#include "bios.h"
#include "common/bytes.h"

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BIOS_START (0xbfc00000)

static const struct memory_range BIOS_RANGE = {.start = BIOS_START, .length = BIOS_SIZE};

bool memory_range_contains(struct memory_range* range, uint32_t address, uint32_t* offset)
{
    uint32_t end_of_range = range->start + range->length;
    if (range->start <= address && address < end_of_range)
    {
        *offset = address - range->start;
        return true;
    }
    return false;
}

uint32_t load32(const struct interconnect* interconnect, uint32_t address)
{
    uint32_t offset;

    if (memory_range_contains(&BIOS_RANGE, address, &offset))
    {
        return read_u32_le(&interconnect->bios.data[offset]);
    }

    fprintf(stderr, "Unhandled load32 at address 0x%08" PRIx32 "\n", address);
    exit(1);
}
