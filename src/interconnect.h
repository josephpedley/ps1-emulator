#pragma once 

#include <stdint.h>
#include <stdbool.h>

struct memory_range
{
    uint32_t start;
    uint32_t length;
};

// takes a range and an address and returns the offset in the range the address is at.
bool memory_range_contains(struct memory_range* range, uint32_t address, uint32_t* offset);






