// Filename:  gdt.h
// Description:  全局段描述表
// Compiler:  gcc

#include "types.h"
#include "asm.h"

// 全局描述符类型
typedef struct gdt_entry_t 
{
	uint16 limit_low;     // 段界限   15～0
	uint16 base_low;      // 段基地址 15～0
	uint8  base_middle;   // 段基地址 23～16
	uint8  access;        // 段存在位、描述符特权级、描述符类型、描述符子类别
	uint8  granularity;   // 其他标志、段界限 19～16
	uint8  base_high;     // 段基地址 31～24
} __attribute__((packed)) gdt_entry_t;

// GDTR
typedef struct gdt_ptr_t 
{
	uint16 limit; 	// 全局描述符表限长
	uint32 base; 		// 全局描述符表 32位 基地址
} __attribute__((packed)) gdt_ptr_t;

// 初始化全局描述符表
void init_gdt();
// 全局描述符表构造函数，根据下标构造
static void gdt_set_gate(int32 num, uint32 base, uint32 limit, uint8 access, uint8 gran);