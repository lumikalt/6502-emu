#include "../include/lib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  CPU cpu;
  Mem *mem = malloc(MEM_SIZE * 16);

  cpu_reset(&cpu, mem);
  (*mem)[0xFFFC] = 0xA9;
  (*mem)[0xFFFD] = 11;

  cpu_exec(&cpu, mem, 2);

  printf("%d\n", cpu.a);

  free(mem);
}
