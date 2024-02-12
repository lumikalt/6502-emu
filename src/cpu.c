#include "../include/lib.h"
#include <stdio.h>

Byte fetchb(CPU *cpu, Mem *mem, size_t *cycles) {
  (*cycles)--;
  return (*mem)[cpu->pc++];
}
Word fetchw(CPU *cpu, Mem *mem, size_t *cycles) {
  Word h = fetchb(cpu, mem, cycles);
  Word l = fetchb(cpu, mem, cycles);
  return (h << 8) | l;
}
Byte readb(const Mem *mem, Byte addr, size_t *cycles) {
  (*cycles)--;
  return (*mem)[addr];
}
Byte readw(const Mem *mem, Byte addr, size_t *cycles) {
  Word h = readb(mem, addr, cycles);
  Word l = readb(mem, addr + 1, cycles);
  return (h << 8) | l;
}

/// When writing values to memory/registers, \
/// set the flags Zero and Negative as appropriate.
void flags_write_value(CPU *cpu, Byte v) {
  cpu->z = v == 0;
  cpu->n = (v & 0b10000000) != 0;
}

void cpu_reset(CPU *cpu, Mem *mem) {
  cpu->pc = 0xFFFC;
  cpu->sp = 0x00;
  cpu->c = cpu->z = cpu->i = cpu->d = cpu->b = cpu->v = cpu->n = 0;
  cpu->a = cpu->x = cpu->y = 0;

  mem_clear(mem);
}

void cpu_exec(CPU *cpu, Mem *mem, size_t cycles) {
  while (cycles > 0) {
    Byte instruction = fetchb(cpu, mem, &cycles);

    switch (instruction) {
    case 0b11101000: { // inx
      // TODO: This doesn't check for overflow.
      Byte x = ++cpu->x;
      cycles--;

      flags_write_value(cpu, x);
    } break;
    case 0b10101001: { // imm lda
      Byte imm = fetchb(cpu, mem, &cycles);
      cpu->a = imm;

      flags_write_value(cpu, imm);
    } break;
    case 0b10100101: { // zp lda
      Byte zp_addr = fetchb(cpu, mem, &cycles);
      cpu->a = readb(mem, zp_addr, &cycles);

      flags_write_value(cpu, cpu->a);
    } break;
    default:
      printf("Unrecognized instruction %04x\n", instruction);
    }
  }
}
