// Filename:  load.h
// Description:  load.s的函数声明
// Compiler:  gcc

void load_idtr(int limit, int addr);
void load_gdtr(int limit, int addr);