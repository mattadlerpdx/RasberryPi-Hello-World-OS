#include "mm.h"

.section ".text.boot"

.globl _start
_start:
	mrs	x0, mpidr_el1	//mrs means load value from system to gener purpose register	
	and	x0, x0,#0xFF	// Check processor id. Perferm logical AND operation
	cbz	x0, master		// Hang for all non-primary CPU
	b	proc_hang

proc_hang: 
	b 	proc_hang

master:
	adr	x0, bss_begin // 
	adr	x1, bss_end
	sub	x1, x1, x0
	bl 	memzero      //(Branch with Link) Perform unconditional Branch, store return address in x30 (linke register)

	mov	sp, #LOW_MEMORY 
	bl	kernel_main
	b 	proc_hang		// should never come here