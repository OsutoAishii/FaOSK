// Filename:  entry.c
// Description:  内核的入口函数
// Compiler:  gcc

#include "math.h"
#include "types.h"
#include "stdio.h"
#include "gdt_idt.h"
#include "asm.h"

int kernel_main()
{
	printf("Initialization the GDT and IDT.\n");
	init_gdt();
	printf("Initialization GDT over.\n");
	init_idt();
	printf("Initialization IDT over.\n");
	for(;;)
	{
		tohlt();
	}
}
