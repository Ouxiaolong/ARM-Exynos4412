	.arm
	.globl	_start
_start:
	B		reset
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP
	NOP

reset:
	LDR		SP, =stack_top

	BL		main
	
__die:
	B		__die

	/** void __delay(void)*/
	.global __delay
__delay:
	PUSH	{R2, LR}

	MOV		R2, #0x20000000
loop1:
	SUBS	R2, R2, #0x1
	BNE		loop1

	POP		{R2, LR}
	MOV		PC, LR

	.data
	.space 8192
stack_top:

	.end
