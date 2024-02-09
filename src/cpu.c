#include "../include/lib.h"
#include <stdio.h>

Byte read_byte(CPU *cpu, Mem *mem, size_t *cycles) {
  (*cycles)--;
  return (*mem)[cpu->pc++];
}

Word read_word(CPU *cpu, Mem *mem, size_t *cycles) {
  Word h = read_byte(cpu, mem, cycles);
  Word l = read_byte(cpu, mem, cycles);
  return (h << 8) | l;
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
    Byte instruction = read_byte(cpu, mem, &cycles);

    switch (instruction) {
    case 0b11101000: { // inx
      Byte x = ++cpu->x;
      cycles--;

      cpu->z = x == 0;
      cpu->n = (x & 0b100000000) != 0;
    } break;
    case 0b10101001: { // imm lda
      Byte imm = read_byte(cpu, mem, &cycles);
      cpu->a = imm;

      cpu->z = imm == 0;
      cpu->n = (imm & 0b10000000) != 0;
    } break;
    default:
      printf("Unrecognized instruction %04x\n", instruction);
    }
  }
}
