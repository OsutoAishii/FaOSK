;Filename:  asm.s
;Description:  一些汇编代码，完成c语言无法完成的底层操作
;Compiler:  gcc

[BITS 32]						; 3制作32位模式用的机器语言
		GLOBAL	load_gdtr, load_idtr, tohlt

[SECTION .text]
	
tohlt:	; void tohlt(void);
    HLT
    RET
;End

load_gdtr:		; void load_gdtr(int limit, int addr);
    MOV		AX,[ESP+4]		; limit
    MOV		[ESP+6],AX
    LGDT	[ESP+6]
    RET
;End

load_idtr:		; void load_idtr(int limit, int addr);
    MOV		AX,[ESP+4]		; limit
    MOV		[ESP+6],AX
    LIDT	[ESP+6]
    RET
;End