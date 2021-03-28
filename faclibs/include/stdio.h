// Filename:  stdio.h
// Description:  标准输入输出库
// Compiler:  gcc

#ifndef STDIO_H
#define STDIO_H

#include "display.h"

//可变形参表的定义
typedef __builtin_va_list va_list;
#define va_start(ap, last)         (__builtin_va_start(ap, last))
#define va_arg(ap, type)           (__builtin_va_arg(ap, type))
#define va_end(ap) 

#define is_digit(c)	((c) >= '0' && (c) <= '9')

#define ZEROPAD		1	// pad with zero
#define SIGN	 	2   	// unsigned/signed long
#define PLUS    	4	// show plus
#define SPACE	  	8   	// space if plus
#define LEFT	 	16  	// left justified
#define SPECIAL		32  	// 0x
#define SMALL	  	64  	// use 'abcdef' instead of 'ABCDEF'

#define do_div(n,base) ({ \
	int __res; \
	__asm__("divl %4":"=a" (n),"=d" (__res):"0" (n),"1" (0),"r" (base)); \
	__res; })

//其他定义
#define assert(x, info)\
	do\ 
	{\
		if (!(x))\ 
		{\
			panic(info);\
		}\
	}\ 
	while (0)

// 编译期间静态检测
#define static_assert(x)  switch (x) { case 0: case (x): ; }

// 打印当前的函数调用栈信息
void panic(const char *msg);

// 打印当前的段存器值
void print_cur_status();

// 内核的打印函数
void printf(const char *format, ...);

// 内核的打印函数 带颜色
void printfColor(ColorType back, ColorType fore, const char *format, ...);

static int vsprintf(char *buff, const char *format, va_list args);

#endif
