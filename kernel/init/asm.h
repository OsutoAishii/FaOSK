// Filename:  asm.h
// Description:  asm.s的函数声明
// Compiler:  gcc

void tohlt(void);
void load_gdtr(uint32);
void load_idtr(int limit, int addr);