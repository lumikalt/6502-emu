#pragma once

#include "./mem.h"
#include "./util.h"

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
  Byte c : 1, z : 1, i : 1, d : 1, b : 1, v : 1, n : 1;
} CPU;

/// Bootup Sequence.
/// TODO: Properly implement it, as the C64 does a few things.
void cpu_reset(CPU *, Mem *);

void cpu_exec(CPU *, Mem *, size_t);
