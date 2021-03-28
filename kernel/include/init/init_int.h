// Filename:  init_int.h
// Description:  初始化中断函数
// Compiler:  gcc

#ifndef INIT_INT_H
#define INIT_INT_H

#include "types.h"

//初始化中断
void init_int();

//初始化时间中断
void init_timer(uint32 frequency);

#endif
