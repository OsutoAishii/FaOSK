// Filename:  gdt.h
// Description:  全局段描述表,中断描述表
// Compiler:  gcc

#include "types.h"

//使用结构体抽象出GDT
struct GDT
{
	int16 limit_low, base_low;
	int8 base_mid, access_right;
	int8 limit_high, base_high;
};

//使用结构体抽象出IDT
struct IDT 
{
	int16 offset_low, selector;
	int8 dw_count, access_right;
	int8 offset_high;
};

//初始化GDT函数
void init_gdt(void);
//设置GDT函数
void set_gdt(struct GDT *sd, unsigned int limit, int base, int ar);
//初始化IDT函数
void init_idt(void);
//设置IDT函数
void set_idt(struct IDT *gd, int offset, int selector, int ar);