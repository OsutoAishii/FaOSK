// Filename:  entry.c
// Description:  内核的入口函数
// Compiler:  gcc

#include "easyio.h"
#include "math.h"
#include "types.h"
#include "stdio.h"
#include "gdt.h"
#include "idt.h"

int kernel_main()
{
	init_gdt();
	init_idt();
	console_clear();
	int i=0;
	for(i=0;;i++)
	{
		putc_color(random()%256,black,random()%16); 
		for(int j=0;j<3000;j++) 
		{
			j++;
		}
	}
}
