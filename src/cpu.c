#include "cpu.h"
#include "interconnect.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define RESET_VECTOR (0xbfc00000)

void cpu_reset(struct CPU* cpu, struct interconnect *interconnect) 
{
  cpu->pc = RESET_VECTOR;
  cpu->interconnect = interconnect;
}

void cpu_step(struct CPU* cpu)
{
    uint32_t instruction = load32(cpu->interconnect, cpu->pc);
    cpu->pc += 4;
    cpu_decode(cpu, instruction);
}


void cpu_decode(struct CPU* cpu, uint32_t instruction)
{
fprintf(stderr, "Unhandled instruction 0x%08" PRIx32 " at 0x%08" PRIx32 "\n",
        instruction, cpu->pc - 4);
exit(1);
}
