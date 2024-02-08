#pragma once

#include "util.h"

#define MEM_SIZE 1024 * 64

typedef Byte Mem[MEM_SIZE];

void mem_clear(Mem *);
