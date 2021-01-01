// Filename:  gdt.h
// Description:  全局段描述表
// Compiler:  gcc

struct SEGMENT_DESCRIPTOR 
{
	short limit_low, base_low;
	char base_mid, access_right;
	char limit_high, base_high;
};

void init_gdt(void);

void set_segmdesc(struct SEGMENT_DESCRIPTOR *sd, unsigned int limit, int base, int ar);