#pragma once

#include "./lib.h"

typedef struct {
  Word pc; // Program Counter
  Byte sp; // Stack Pointer

  // Registers:
  // a: Accumulator
  // x & y: Index Registers
  Byte a, x, y;

  // Processor Status Flags
  // Carry; Zero; Interrupt disable; Decimal mode;
  // Break command; oVerflow; Negative
  Byte c, z, i, d, b, v, n : 1;
} CPU;

void cpu_reset(CPU *cpu);
