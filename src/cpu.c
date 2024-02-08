#include "../include/lib.h"

void cpu_reset(CPU *cpu) {
  cpu->pc = 0xFFFC;
  cpu->sp = 0x00;
  cpu->c = cpu->z = cpu->i = cpu->d = cpu->b = cpu->v = cpu->n = 0;
  cpu->a = cpu->x = cpu->y = 0;
}
