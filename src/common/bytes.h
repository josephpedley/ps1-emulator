#pragma once 

#include <stdint.h>
static inline uint32_t read_u32_le(const uint8_t* byte)
{
    return ((uint32_t) *byte) | ((uint32_t) byte[1] << 8) 
                              | ((uint32_t) byte[2] << 16)
                              | ((uint32_t) byte[3] << 24);
}  
