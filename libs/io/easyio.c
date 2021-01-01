// Filename:  easyio.c
//Description:  屏幕操作的一些函数实现
// Compiler:  gcc

#include "easyio.h"
#include "ports.h"

// VGA 的显示缓冲的起点是 0xB8000
static uint16 *video_memory = (uint16 *)0xB8000;

// 屏幕"光标"的坐标
static uint8 cursor_x = 0;
static uint8 cursor_y = 0;

// 移动光标
static void move_cursor()
{
	// 屏幕是 80 字节宽
	uint16 cursorLocation = cursor_y * 80 + cursor_x;

	outb(0x3D4, 14);                  	// 告诉 VGA 我们要设置光标的高字节
	outb(0x3D5, cursorLocation >> 8); 	// 发送高 8 位
	outb(0x3D4, 15);                  	// 告诉 VGA 我们要设置光标的低字节
	outb(0x3D5, cursorLocation);     	// 发送低 8 位
}

// 屏幕滚动操作
static void scroll()
{
	// attribute_byte 被构造出一个黑底白字的描述格式
	uint8 attribute_byte = (0 << 4) | (15 & 0x0F);
	uint16 blank = 0x20 | (attribute_byte << 8);  // space 是 0x20

	// cursor_y 到 25 的时候换行
	if (cursor_y >= 25) {
		// 将所有行的显示数据复制到上一行
		int i;
		for (i = 0 * 80; i < 24 * 80; i++) {
		      video_memory[i] = video_memory[i+80];
		}

		// 最后的一行数据现在填充空格
		for (i = 24 * 80; i < 25 * 80; i++) {
		      video_memory[i] = blank;
		}

		// 向上移动了一行，cursor_y 是 24
		cursor_y = 24;
	}
}

// 清屏操作
void console_clear()
{
	uint8 attribute_byte = (0 << 4) | (15 & 0x0F);
	uint16 blank = 0x20 | (attribute_byte << 8);

	int i;
	for (i = 0; i < 80 * 25; i++) {
	      video_memory[i] = blank;
	}

	cursor_x = 0;
	cursor_y = 0;
	move_cursor();
}

// 输出一个字符，可指定颜色
void putc_color(char c, ColorType back, ColorType fore)
{
	uint8 back_color = (uint8)back;
	uint8 fore_color = (uint8)fore;

	uint8 attribute_byte = (back_color << 4) | (fore_color & 0x0F);
	uint16 attribute = attribute_byte << 8;

	// 0x08 是 退格键 的 ASCII 码
	// 0x09 是 tab 键 的 ASCII 码
	if (c==0x08&&cursor_x) {cursor_x--;} 
	else if (c == 0x09)    {cursor_x = (cursor_x+8) & ~(8-1);}
	else if (c == '\r')    {cursor_x = 0;}
	else if (c == '\n')    {cursor_x = 0; cursor_y++;} 
	else if (c >= ' ')     {video_memory[cursor_y*80 + cursor_x] = c | attribute; cursor_x++;}

	// 每 80 个字符一行，满80就换行
	if (cursor_x >= 80) 
	{
		cursor_x = 0;
		cursor_y ++;
	}

	// 需要的话滚动屏幕
	scroll();

	// 移动硬件的输入光标
	move_cursor();
}

// 输出一个以“\0”结尾的字符串，黑底白字
void printS(char *cstr)
{
	while (*cstr) 
	{
	    putc_color(*cstr++, black, white);
	}
}

// 输出一个以“\0”结尾的字符串，可指定颜色
void printSColor(char *cstr, ColorType back, ColorType fore)
{
	while (*cstr) 
	{
	    putc_color(*cstr++, back, fore);
	}
}

// 输出一个十六进制的整型数
void print_hex(uint32 n, ColorType back, ColorType fore)
{
	int tmp;
	char noZeroes = 1;

	printSColor("0x", back, fore);

	int i;
	for (i = 28; i >= 0; i -= 4) 
	{
		tmp = (n >> i) & 0xF;
		if (tmp == 0 && noZeroes != 0) 
		{
		    continue;
		}
		noZeroes = 0;
		if (tmp >= 0xA) 
		{
		    putc_color(tmp-0xA+'a', back, fore);
		} 
		else 
		{
		    putc_color(tmp+'0', back, fore);
		}
	}
}

// 输出一个十进制的整型数
void print_dec(uint32 n, ColorType back, ColorType fore)
{
	if (n == 0) 
	{
		putc_color('0', back, fore);
		return;
	}

	uint32 acc = n;
	char c[32];
	int i = 0;
	while (acc > 0) 
	{
		c[i] = '0' + acc % 10;
		acc /= 10;
		i++;
	}
	c[i] = 0;

	char c2[32];
	c2[i--] = 0;

	int j = 0;
	while(i >= 0) 
	{
	    c2[i--] = c[j++];
	}

	printSColor(c2, back, fore);
}