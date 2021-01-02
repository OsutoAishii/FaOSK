// Filename:  ports.c
// Description:  端口输入输出函数
// Compiler:  gcc

#include "ports.h"

// 端口写一个字节
inline void outb(uint16 port, uint8 value)
{
	asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

// 端口读一个字节
inline uint8 inb(uint16 port)
{
	uint8 ret;
	asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}

// 端口读一个字节
inline uint16 inw(uint16 port)
{
	uint16 ret;
	asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
	return ret;
}
