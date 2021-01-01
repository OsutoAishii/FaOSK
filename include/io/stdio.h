// Filename:  stdio.h
// Description:  标准输入输出库
// Compiler:  gcc

#ifndef INCLUDE_DEBUG_H_
#define INCLUDE_DEBUG_H_

#include "easyio.h"

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

#endif 	// INCLUDE_DEBUG_H_
