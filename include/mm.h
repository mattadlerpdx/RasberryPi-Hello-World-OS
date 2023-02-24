//memory management header file, taken straight from LINUX source code
//initially set off where low memory will be, i.e. where stack pointer is.
#pragma once

#define PAGE_SHFT 12
#define TABLE_SHIFT 9
#define SECTION_SHIFT (PAGE_SHIFT +TABLE_SHIFT)
#define PAGE_SIZE (1 << PAGE_SHIFT)
#define SECTION_SIZE (1 << SECTION_SHIFT)

#define LOW_MEMORY (2 * SECION_SIZE)

#ifndef __ASSEMBLER__
//include this section so we can include in assembler and c files
void memzero(unsigned long src, unsigned int n);

#endif

