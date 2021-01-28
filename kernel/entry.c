// Filename:  entry.c
// Description:  内核的入口函数
// Compiler:  gcc

#include "math.h"
#include "types.h"
#include "stdio.h"
#include "asm.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"

int kernel_main()
{
	console_clear();
	printf("Boot FaOSK from GRUB...\n");

	printf("Initialization GDT.\n");
	init_gdt();
	printf("Initialization GDT over.\n");

	printf("Initialization iDT.\n");
	init_idt();
	printf("Initialization IDT over.\n");

	printf("Initialization Timer INT.\n");
	init_timer(1000);
	printf("Initialization Timer INT over.\n");

	printf("Boot over!\n");
	asm volatile ("sti");
}
