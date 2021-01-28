// Filename:  timer.h
// Description:  定义 PIT(周期中断定时器) 相关函数
// Compiler:  gcc

#include "timer.h"
#include "easyio.h"
#include "stdio.h"
#include "idt.h"

static int64 total_second;

//定时器中断函数
void timer_call(pt_regs *regs)
{
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
		set_cursor(0,8);
		printf("%.2d:%.2d:%.2d\n",hour,min,sec);
	}
}

//初始化时间中断
void init_timer(uint32 frequency)
{
	total_second = 0;
	// 注册时间相关的处理函数
	reg_INT_handler(IRQ0, timer_call);
	// Intel 8253/8254 PIT芯片 I/O端口地址范围是40h~43h
	// 输入频率为 1193180，frequency 即每秒中断次数
	uint32 divisor = 1193180 / frequency;
	// D7 D6 D5 D4 D3 D2 D1 D0
	// 0  0  1  1  0  1  1  0
	// 即就是 36 H
	// 设置 8253/8254 芯片工作在模式 3 下
	outb(0x43, 0x36);
	// 拆分低字节和高字节
	uint8 low = (uint8)(divisor & 0xFF);
	uint8 hign = (uint8)((divisor >> 8) & 0xFF);
	// 分别写入低字节和高字节
	outb(0x40, low);
	outb(0x40, hign);
}

//获取时间
int64 get_total_second()
{
	return total_second;
}
