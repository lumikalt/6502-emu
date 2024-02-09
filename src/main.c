#include "../include/lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  CPU cpu;
  Mem *mem = malloc(MEM_SIZE * 2);

  cpu_reset(&cpu, mem);
  cpu.x = 2;
  (*mem)[0xFFFC] = 0xE8;

  cpu_exec(&cpu, mem, 2);

  printf("0x%02x\n", cpu.x);

  free(mem);
}
