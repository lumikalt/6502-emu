#include "../include/lib.h"
#include <stdlib.h>

int main(void) {
  CPU cpu;
  Mem *mem = malloc(MEM_SIZE * 16);

  cpu_reset(&cpu, mem);
}
