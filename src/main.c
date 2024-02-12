#include "../include/lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  CPU cpu;
  Mem *mem = malloc(MEM_SIZE * 2);

  cpu_reset(&cpu, mem);
  (*mem)[0xFFFC] = 0xA5;
  (*mem)[0xFFFD] = 0x11;
  (*mem)[0x0011] = 0x42;
  cpu_exec(&cpu, mem, 3);

  printf("0x%02x\n", cpu.a);

  free(mem);
}
