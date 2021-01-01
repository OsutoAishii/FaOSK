// Filename:  idt.h
// Description:  中断描述表
// Compiler:  gcc

struct GATE_DESCRIPTOR 
{
	short offset_low, selector;
	char dw_count, access_right;
	short offset_high;
};

void init_idt(void);

void set_gatedesc(struct GATE_DESCRIPTOR *gd, int offset, int selector, int ar);