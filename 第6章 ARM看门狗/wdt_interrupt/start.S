	.arch armv7-a
	.arm


	.text
	.align 2

	.globl	_start
_start:
	B	__reset
	LDR	PC, __undefined_instruction
	LDR	PC, __swi_handler
	LDR	PC, __prefetch_abort
	LDR	PC, __data_abort
	LDR	PC, __reserved_handler
	LDR	PC, __irq_handler
	LDR	PC, __fiq_handler

	.align 5
__reset:			B	real_reset
__undefined_instruction: 	.word __undefined_instruction
__swi_handler: 			.word __swi_handler
__prefetch_abort: 		.word __prefetch_abort
__data_abort: 			.word __data_abort
__reserved_handler:		.word __reserved_handler
__irq_handler:			.word irq_handler
__fiq_handler:			.word __fiq_handler

	.align 5
real_reset:
	MOV		R0, #0x40000000
	mcr		p15,0,R0,c12,c0,0

	/* Switch Into SVC Mode */
	MRS		R0, CPSR
	BIC		R0, R0, #0x1F
	ORR		R0, R0, #0x0D3 @@ Disable IRQ and Disable FIQ
	MSR		CPSR_c, R0
	/* svc Mode Stack Initialization */
	LDR		SP, =svc_stack_top


	/* Switch Into IRQ Mode */
	MSR		CPSR_c, #0x0D2 @@ 0x110_10010: 0x1101_0010
	/* irq Mode Stack Initialization */
	LDR		SP, =irq_stack_top

	/* Switch Into USR Mode and Disable IRQ */
	MSR		CPSR_c, #0x50 @@ 0b0(I)1(F)0(T)_10000
	LDR		SP, =usr_stack_top

	BL		main
	
__die:
	B		__die

	.align 4
irq_handler:
	SUB		LR, LR, #0x4
	STMFD		SP!, {R0-R12, LR}
	BL		do_irq
	LDMFD		SP!, {R0-R12, PC}^


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
	
	.align 2
	.global raise
raise:
	MOV	PC, LR

	.data
	.space 8192
usr_stack_top:
	.space 1024
__reserved:
	.space 4096
svc_stack_top:
	.space 4096
irq_stack_top:

	.end
