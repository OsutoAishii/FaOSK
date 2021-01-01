// Filename:  string.h
// Description:  字符串处理函数
// Compiler:  gcc

#ifndef INCLUDE_STRING_H_
#define INCLUDE_STRING_H_

#include "types.h"

//内存拷贝函数
static inline void memcpy(uint8 *dest, const uint8 *src, uint32 len);

//内存赋值函数
static inline void memset(void *dest, uint8 val, uint32 len);

//内存清空（全部为0）函数
static inline void bzero(void *dest, uint32 len);

static inline int strcmp(const char *str1, const char *str2);

//字符串拷贝函数
static inline char *strcpy(char *dest, const char *src);

//字符串截取函数
static inline char *strcat(char *dest, const char *src);

//获取字符串长度函数
static inline int strlen(const char *src);

#endif 	// INCLUDE_STRING_H_
