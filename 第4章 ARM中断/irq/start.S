	.arch armv7-a
	.arm
	.globl	_start
_start:
	B		reset
	NOP
	NOP
	NOP
	NOP
	NOP
	@@@@ B		irq_handler
	@@@@ LDR		PC, [Rx]
	LDR		PC, __irq_handler
	NOP

__irq_handler:	.word irq_handler

reset:
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
	MSR		CPSR_c, #0x0D2
	/* irq Mode Stack Initialization */
	LDR		SP, =irq_stack_top

	/* Switch Into USR Mode and Enable IRQ */
	MSR		CPSR_c, #0x50 @@ 0b0(I)1(F)0(T)_10000
	LDR		SP, =usr_stack_top

	BL		main
	
__die:
	B		__die

	.align 4
	/* void do_irq(void) */
irq_handler:
	STMFD	SP!, {R0-R12, LR}
	BL		do_irq
	LDMFD	SP!, {R0-R12, PC}^

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
usr_stack_top:
	.space 1024
__reserved:
	.space 4096
svc_stack_top:
	.space 4096
irq_stack_top:

	.end
