// Filename:  asm.h
// Description:  asm.s的函数声明
// Compiler:  gcc

#ifndef ASM_H
#define ASM_H

//hlt函数
void tohlt(void);

//加载gdtr函数
void load_gdtr(uint32);

//加载idtr函数
void load_idtr(int limit, int addr);

#endif
