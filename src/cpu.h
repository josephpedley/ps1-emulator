#pragma once

#include "interconnect.h"

#include <stdint.h>

struct CPU
{
    struct interconnect* interconnect;
    uint32_t pc;

    uint32_t registers[32];
};

void cpu_reset(struct CPU* cpu, struct interconnect* interconnect);

void cpu_decode(struct CPU* cpu, uint32_t instruction);

void cpu_step(struct CPU* cpu);
