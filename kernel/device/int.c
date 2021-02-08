// Filename:  int.c
// Description:  中断处理函数
// Compiler:  gcc

#include "int.h"
#include "idt.h"
#include "ports.h"
#include "types.h"
#include "easyio.h"
#include "keybroad.h"

//定时器中断函数
void timer_call(pt_regs *regs)
{
    CursorAddress cursor;
	static uint32 tick = 0;
	static int32 sec = 0;
	static int32 min = 0;
	static int32 hour = 0;
	tick++;
	if(tick>=1000)
	{
		tick=0;
		sec++;
		total_second++;
		if(sec>=60)
		{
			sec=0;
			min++;
		}
		if(min>=60)
		{
			min=0;
			hour++;
		}
		cursor=set_cursor(0,8);
		printf("%.2d:%.2d:%.2d\n",hour,min,sec);
        set_cursor(cursor.x,cursor.y);
		printf(" \b");
	}
}

//获取时间
int64 get_total_second()
{
	return total_second;
}

//键盘中断函数
void keyboard_call(pt_regs *regs)
{
	unsigned char be_data,af_data;
	be_data=inb(0x0060);
	af_data = data_hander(be_data);
	printf("%c",af_data);
}
