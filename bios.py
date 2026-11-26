#!/usr/bin/env python3
from pathlib import Path
import array

file_path = Path("./ps_files/SCPH1001.BIN")

instructions = array.array("I")
instructions.frombytes(file_path.read_bytes())

# Manually add opcodes you've already implemented here (in hex, binary, or decimal)
handled_opcodes = {
        0x0F
}

seen_opcodes = set(handled_opcodes)

for index, inst in enumerate(instructions, start=1):
    opcode = (inst >> 26) & 0x3F
    
    if opcode not in seen_opcodes:
        seen_opcodes.add(opcode)
        inst_str = f"0x{inst:08X}"
        print(f"Instruction {index}: {inst_str} | Opcode: 0b{opcode:06b} (0x{opcode:02X})")

print(f"\nProgress: {len(handled_opcodes)}/{len(seen_opcodes)} unique opcodes handled.")
