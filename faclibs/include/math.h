// Filename:  math.h
// Description:  有关数学的一些函数和定义
// Compiler:  gcc

#ifndef MATH_H
#define MATH_H

#include "types.h"

//随机数函数
int rand(int seed);

//随机数列
int random();

//计算乘方的函数
int power_int(int base,int index);

//绝对值函数
int abs(int x);

//小数版绝对值函数
double fabs(double x);

#endif
