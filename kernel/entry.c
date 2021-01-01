// Filename:  entry.c
// Description:  内核的入口函数
// Compiler:  gcc

#include "easyio.h"

int kernel_main()
{
	console_clear();
	for(int i=0;;i++)
	{
		if (i%2==0)
		{
			printSColor("A",rc_black,rc_blue);
		}
		else
		{
			printSColor("B",rc_black,rc_red);
		}
	}
	return 0;
}