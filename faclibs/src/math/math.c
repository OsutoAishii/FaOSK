// Filename:  math.c
// Description:  有关数学的一些函数和定义
// Compiler:  gcc

#include "math.h"
#include "types.h"

//随机数函数
int rand(int seed)
{
    int a=9,b=7,max =9199; 
    int temp=a*seed+b;
    return(temp%max);
}

//随机数列
int random()
{
    static s0=11,s1=23,s2=29;
    int a=9,b=7,c=11,d=13,max =9199; 
    int s3=(a*s0+b*s1+c*s2+d)%max;
    s0=s1;
    s1=s2;
    s2=s3;
    return s3;
}

//计算乘方的函数
int power_int(int base,int index)
{
    int mul=base;
    for(int i=0;i<index-1;i++)
    {
        mul *=base;
    }
    return(mul);
}

//绝对值函数
int abs(int x)
{
    if(x>=0)
    {
        return x;
    }
    else
    {
        return (x*-1);
    }
}

//小数版绝对值函数
double fabs(double x)
{
    if(x>=0)
    {
        return x;
    }
    else
    {
        return (x*-1);
    }
}
