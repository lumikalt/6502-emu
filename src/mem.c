#include "../include/lib.h"
#include <stddef.h>

void mem_clear(Mem *mem) {
  for (size_t i = 0; i < MEM_SIZE; i++)
    (*mem)[i] = 0;
}
