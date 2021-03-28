// Filename:  int.h
// Description:  中断处理函数
// Compiler:  gcc

#ifndef INT_H
#define INT_H

#include "types.h"
#include "idt.h"

static int64 total_second;

//定时器中断函数
void timer_call(pt_regs *regs);

//获取时间
int64 get_total_second();

//键盘中断函数
void keyboard_call(pt_regs *regs);

#endif
