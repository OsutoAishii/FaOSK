// Filename:  idt.h
// Description:  中断描述表
// Compiler:  gcc

#include "easyio.h"
#include "string.h"
#include "idt.h"
#include "stdio.h"

// 中断描述符表
idt idts[256];

// IDTR
idtr idt_ptr;

// 中断处理函数的指针数组
INT_handler INT_handlers[256];

// 初始化中断描述符表
void init_idt()
{	
	// 重新映射 IRQ 表
	// 两片级联的 Intel 8259A 芯片
	// 主片端口 0x20 0x21
	// 从片端口 0xA0 0xA1

	// 初始化主片、从片
	// 0001 0001
	outb(0x20, 0x11);
	outb(0xA0, 0x11);
	// 设置主片 IRQ 从 0x20(32) 号中断开始
	outb(0x21, 0x20);
	// 设置从片 IRQ 从 0x28(40) 号中断开始
	outb(0xA1, 0x28);
	// 设置主片 IR2 引脚连接从片
	outb(0x21, 0x04);
	// 告诉从片输出引脚和主片 IR2 号相连
	outb(0xA1, 0x02);
	// 设置主片和从片按照 8086 的方式工作
	outb(0x21, 0x01);
	outb(0xA1, 0x01);
	// 设置主从片允许中断
	outb(0x21, 0x0);
	outb(0xA1, 0x0);
	bzero((uint8 *)&INT_handlers, sizeof(INT_handler) * 256);
	idt_ptr.limit = sizeof(idt) * 256 - 1;
	idt_ptr.base  = (uint32)&idts;
	bzero((uint8 *)&idts, sizeof(idt) * 256);
	// 0-32:  用于 CPU 的中断处理
	idt_set( 0, (uint32)isr0,  0x08, 0x8E);
	idt_set( 1, (uint32)isr1,  0x08, 0x8E);
	idt_set( 2, (uint32)isr2,  0x08, 0x8E);
	idt_set( 3, (uint32)isr3,  0x08, 0x8E);
	idt_set( 4, (uint32)isr4,  0x08, 0x8E);
	idt_set( 5, (uint32)isr5,  0x08, 0x8E);
	idt_set( 6, (uint32)isr6,  0x08, 0x8E);
	idt_set( 7, (uint32)isr7,  0x08, 0x8E);
	idt_set( 8, (uint32)isr8,  0x08, 0x8E);
	idt_set( 9, (uint32)isr9,  0x08, 0x8E);
	idt_set(10, (uint32)isr10, 0x08, 0x8E);
	idt_set(11, (uint32)isr11, 0x08, 0x8E);
	idt_set(12, (uint32)isr12, 0x08, 0x8E);
	idt_set(13, (uint32)isr13, 0x08, 0x8E);
	idt_set(14, (uint32)isr14, 0x08, 0x8E);
	idt_set(15, (uint32)isr15, 0x08, 0x8E);
	idt_set(16, (uint32)isr16, 0x08, 0x8E);
	idt_set(17, (uint32)isr17, 0x08, 0x8E);
	idt_set(18, (uint32)isr18, 0x08, 0x8E);
	idt_set(19, (uint32)isr19, 0x08, 0x8E);
	idt_set(20, (uint32)isr20, 0x08, 0x8E);
	idt_set(21, (uint32)isr21, 0x08, 0x8E);
	idt_set(22, (uint32)isr22, 0x08, 0x8E);
	idt_set(23, (uint32)isr23, 0x08, 0x8E);
	idt_set(24, (uint32)isr24, 0x08, 0x8E);
	idt_set(25, (uint32)isr25, 0x08, 0x8E);
	idt_set(26, (uint32)isr26, 0x08, 0x8E);
	idt_set(27, (uint32)isr27, 0x08, 0x8E);
	idt_set(28, (uint32)isr28, 0x08, 0x8E);
	idt_set(29, (uint32)isr29, 0x08, 0x8E);
	idt_set(30, (uint32)isr30, 0x08, 0x8E);
	idt_set(31, (uint32)isr31, 0x08, 0x8E);

	idt_set(32, (uint32)irq0, 0x08, 0x8E);
	idt_set(33, (uint32)irq1, 0x08, 0x8E);
	idt_set(34, (uint32)irq2, 0x08, 0x8E);
	idt_set(35, (uint32)irq3, 0x08, 0x8E);
	idt_set(36, (uint32)irq4, 0x08, 0x8E);
	idt_set(37, (uint32)irq5, 0x08, 0x8E);
	idt_set(38, (uint32)irq6, 0x08, 0x8E);
	idt_set(39, (uint32)irq7, 0x08, 0x8E);
	idt_set(40, (uint32)irq8, 0x08, 0x8E);
	idt_set(41, (uint32)irq9, 0x08, 0x8E);
	idt_set(42, (uint32)irq10, 0x08, 0x8E);
	idt_set(43, (uint32)irq11, 0x08, 0x8E);
	idt_set(44, (uint32)irq12, 0x08, 0x8E);
	idt_set(45, (uint32)irq13, 0x08, 0x8E);
	idt_set(46, (uint32)irq14, 0x08, 0x8E);
	idt_set(47, (uint32)irq15, 0x08, 0x8E);

	// 255 将来用于实现系统调用
	idt_set(255, (uint32)isr255, 0x08, 0x8E);

	// 更新设置中断描述符表
	load_idtr((uint32)&idt_ptr);
}

// 设置中断描述符的函数
static void idt_set(uint8 num, uint32 base, uint16 sel, uint8 flags)
{
	idts[num].base_lo = base & 0xFFFF;
	idts[num].base_hi = (base >> 16) & 0xFFFF;
	idts[num].sel     = sel;
	idts[num].always0 = 0;
	// 先留下 0x60 这个魔数，以后实现用户态时候
	// 这个与运算可以设置中断门的特权级别为 3
	idts[num].flags = flags;  // | 0x60
}

// 调用中断处理函数
void isr_handler(pt_regs *regs)
{
	if (INT_handlers[regs->int_no]) 
	{
		INT_handlers[regs->int_no](regs);
	}
	else 
	{
		printfColor(black,blue,"Unhandled interrupt: %d\n",regs->int_no);
	}
}

// 注册一个中断处理函数
void reg_INT_handler(uint8 n, INT_handler h)
{
	INT_handlers[n] = h;
}

// IRQ 处理函数
void irq_handler(pt_regs *regs)
{
	// 发送中断结束信号给 PICs
	// 按照我们的设置，从 32 号中断起为用户自定义中断
	// 因为单片的 Intel 8259A 芯片只能处理 8 级中断
	// 故大于等于 40 的中断号是由从片处理的
	if (regs->int_no >= 40) 
	{
		outb(0xA0, 0x20); // 发送重设信号给从片
	}
	outb(0x20, 0x20); // 发送重设信号给主片
	if (INT_handlers[regs->int_no]) 
	{
		INT_handlers[regs->int_no](regs);
	}
}
