// Filename:  easyio.h
// Description:  屏幕操作的相关函数的头文件
// Compiler:  gcc

#ifndef EASYIO_H
#define EASYIO_H

#include "types.h"
#include "ports.h"

typedef enum color 
{
	black = 0,
	blue = 1,
	green = 2,
	cyan = 3,
	red = 4,
	magenta = 5,
	brown = 6,
	light_grey = 7,
	dark_grey = 8,
	light_blue = 9,
	light_green = 10,
	light_cyan = 11,
	light_red = 12,
	light_magenta = 13,
	light_brown  = 14,
	white = 15
} ColorType;

typedef struct cursor
{
	int x;
	int y;
} CursorAddress;


//设置光标位置
CursorAddress set_cursor(int x,int y);

// 清屏操作
void console_clear();

// 输出一个字符，可指定颜色
void putc_color(char c, ColorType back, ColorType fore);

// 输出一个以“\0”结尾的字符串，黑底白字
void printS(char *cstr);

// 输出一个以“\0”结尾的字符串，可指定颜色
void printSColor(char *cstr, ColorType back, ColorType fore);

// 输出一个十六进制的整型数
void print_hex(uint32 n, ColorType back, ColorType fore);

// 输出一个十进制的整型数
void print_dec(uint32 n, ColorType back, ColorType fore);

#endif
