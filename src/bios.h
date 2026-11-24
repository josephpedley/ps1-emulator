#pragma once

#include <stdint.h>
#include <stdbool.h>

#define BIOS_SIZE (512 * 1024)

struct Bios
{
    uint8_t data[BIOS_SIZE];
};

// Read BIOS image from disk. Return false if file is missing/wrong size
bool load_bios_image(struct Bios* bios, const char* path);
// Fetch 32 bit word at the given offset into the BIOS
uint32_t load_bios_word(struct Bios* bios, uint32_t offset);
