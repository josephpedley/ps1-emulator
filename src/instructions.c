#include "instructions.h"
#include "cpu.h"
#include <stdint.h>

static void op_lui(struct CPU* cpu, uint32_t instruction)
{
    cpu->registers[get_rt(instruction)] = get_immediate(instruction << 16);
}
