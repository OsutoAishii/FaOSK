// Filename:  gdt_idt.c
// Description:  全局段描述表,中断描述表
// Compiler:  gcc

#include "gdt_idt.h"
#include "asm.h"

//初始化GDT函数
void init_gdt(void)
{
    int i;
	//生成GDT，存放在内存的0x00270000处
    struct GDT *gdt = (struct GDT *) 0x00270000;
    //初始化GDT（全部清0）
	for (i = 0; i < 8192; i++) 
    {
		set_gdt(gdt + i, 0, 0, 0);
	}
	//设置GDT（分两个段，第一个段为平坦模式，第二个从0x0007ffff开始，到0x00280000
	set_gdt(gdt + 1, 0xffffffff, 0x00000000, 0x4092);
	set_gdt(gdt + 2, 0x0007ffff, 0x00280000, 0x409a);
	//加载gdtr
	load_gdtr(0xffff, 0x00270000);

    return;
}

//设置GDT函数
void set_gdt(struct GDT *sd, unsigned int limit, int base, int ar)
{
	//如果段的大小大于1M
	if (limit > 0xfffff) 
    {
		//使全局段描述表中G=1，将单位换为4KB
		ar=ar|0x8000;
		//由于单位变化，将limit位移
		limit=limit/0x1000;
	}
	//设置GDT
	sd->limit_low    = limit & 0xffff;
	sd->base_low     = base & 0xffff;
	sd->base_mid     = (base >> 16) & 0xff;
	sd->access_right = ar & 0xff;
	sd->limit_high   = ((limit >> 16) & 0x0f) | ((ar >> 8) & 0xf0);
	sd->base_high    = (base >> 24) & 0xff;
	return;
}

//初始化IDT函数
void init_idt(void)
{
    int i;
	//生成IDT，存放在内存的0x0026f800处
    struct IDT *idt = (struct IDT *) 0x0026f800;
    //初始化GDT（全部清0）
	for (i = 0; i < 256; i++) 
    {
		set_idt(idt + i, 0, 0, 0);
	}
	//加载idtr
	load_idtr(0x7ff, 0x0026f800);
	return;
}

//设置IDT函数
void set_idt(struct IDT *gd, int offset, int selector, int ar)
{
	//设置IDT
	gd->offset_low   = offset & 0xffff;
	gd->selector     = selector;
	gd->dw_count     = (ar >> 8) & 0xff;
	gd->access_right = ar & 0xff;
	gd->offset_high  = (offset >> 16) & 0xffff;
	return;
}