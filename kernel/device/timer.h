// Filename:  timer.h
// Description:  定义 PIT(周期中断定时器) 相关函数
// Compiler:  gcc

#include "types.h"

//初始化时间中断
void init_timer(uint32 frequency);

//获取时间
int64 get_total_second();