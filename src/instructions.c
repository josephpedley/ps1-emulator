#include "instructions.h"
#include "cpu.h"
#include <stdint.h>

static void op_lui(struct CPU* cpu, uint32_t instruction)
{
    cpu->registers[get_rt(instruction)] = get_immediate(instruction << 16);
}

static void op_blez(struct CPU* cpu, uint32_t instruction)
{
    uint32_t rs = get_rs(instruction);
    uint32_t imm = get_immediate(instruction);

    if (rs <= 0)
    {
        cpu->pc += 4 + imm; 

    }
}


