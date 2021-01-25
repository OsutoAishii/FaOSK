;Filename:  asm.s
;Description:  一些汇编代码，完成c语言无法完成的底层操作
;Compiler:  gcc

GLOBAL load_gdtr,load_idtr, tohlt

[SECTION .text]

;void tohlt(void);	
tohlt:	
    HLT
    RET
;End

;void load_gdtr(uint32);
load_gdtr: 
	mov eax, [esp+4]  ; 参数存入 eax 寄存器
	lgdt [eax]        ; 加载到 GDTR [修改原先GRUB设置]
	mov ax, 0x10      ; 加载我们的数据段描述符
	mov ds, ax        ; 更新所有可以更新的段寄存器
	mov es, ax
	mov fs, ax
	mov gs, ax
	mov ss, ax
	jmp 0x08:.flush   
    ; 远跳转，0x08是我们的代码段描述符
	; 远跳目的是清空流水线并串行化处理器
.flush:
	ret
;End

load_idtr:
	mov eax, [esp+4]  ; 参数存入 eax 寄存器
	lidt [eax]        ; 加载到 IDTR
	ret
;End