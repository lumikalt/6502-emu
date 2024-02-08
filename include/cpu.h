#pragma once

#include "./util.h"
#include "./mem.h"

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

/// Bootup Sequence.
/// TODO: Properly implement it, as the C64 does a few things.
void cpu_reset(CPU *, Mem *);
