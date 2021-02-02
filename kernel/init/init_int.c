// Filename:  init_int.c
// Description:  初始化中断函数
// Compiler:  gcc

#include "init_int.h"
#include "types.h"
#include "idt.h"
#include "int.h"

//初始化中断
void init_int()
{
    //初始化时间中断
    init_timer(1000);
    //初始化键盘中断
    reg_INT_handler(IRQ1, keyboard_call);
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