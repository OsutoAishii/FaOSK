// Filename:  entry.c
// Description:  内核的入口函数
// Compiler:  gcc

#include "stdio.h"
#include "gdt.h"
#include "idt.h"
#include "init_int.h"

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

	printf("Initialization INT.\n");
	init_int();
	printf("Initialization INT over.\n");

	printf("Boot over!\n\n");

	asm volatile ("sti");
}
