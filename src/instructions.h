#pragma once

#include <cstdint>
#include <stdint.h>

static inline uint32_t get_opcode(uint32_t instruction) {
  return instruction >> 26;
}

static inline uint32_t get_rs(uint32_t instruction) {
  return instruction >> 21 & 0x1F;
}

static inline uint32_t get_rt(uint32_t instruction) {
  return instruction >> 16 & 0x1F;
}

static inline uint32_t get_rd(uint32_t instruction) {
  return instruction >> 11 & 0x1F;
}

static inline uint32_t get_shift(uint32_t instruction) {
  return instruction >> 6 & 0x1F;
}

static inline uint32_t get_function(uint32_t instruction) {
  return instruction & 0x3F;
}

static inline uint32_t get_immediate(uint32_t instruction) {
  return instruction & 0xFFFF;
}

static inline uint32_t get_jump_target(uint32_t instruction) {
  return instruction & 0x3FFFFFF;
}

