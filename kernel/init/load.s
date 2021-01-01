[BITS 32]						; 3制作32位模式用的机器语言
		GLOBAL	load_gdtr, load_idtr

[SECTION .text]
	
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