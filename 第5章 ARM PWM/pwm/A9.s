
A9:     file format elf32-littlearm


Disassembly of section .text:

40000000 <_start>:
40000000:	ea000006 	b	40000020 <reset>
40000004:	e320f000 	nop	{0}
40000008:	e320f000 	nop	{0}
4000000c:	e320f000 	nop	{0}
40000010:	e320f000 	nop	{0}
40000014:	e320f000 	nop	{0}
40000018:	e320f000 	nop	{0}
4000001c:	e320f000 	nop	{0}

40000020 <reset>:
40000020:	e59fd01c 	ldr	sp, [pc, #28]	; 40000044 <loop1+0x10>
40000024:	eb000007 	bl	40000048 <main>

40000028 <__die>:
40000028:	eafffffe 	b	40000028 <__die>

4000002c <__delay>:
4000002c:	e92d4004 	push	{r2, lr}
40000030:	e3a02202 	mov	r2, #536870912	; 0x20000000

40000034 <loop1>:
40000034:	e2522001 	subs	r2, r2, #1
40000038:	1afffffd 	bne	40000034 <loop1>
4000003c:	e8bd4004 	pop	{r2, lr}
40000040:	e1a0f00e 	mov	pc, lr
40000044:	40002170 	.word	0x40002170

40000048 <main>:
40000048:	e92d4800 	push	{fp, lr}
4000004c:	e28db004 	add	fp, sp, #4
40000050:	eb000005 	bl	4000006c <pwm_init>
40000054:	eb00002e 	bl	40000114 <beep_on>
40000058:	ebfffff3 	bl	4000002c <__delay>
4000005c:	ebfffff2 	bl	4000002c <__delay>
40000060:	ebfffff1 	bl	4000002c <__delay>
40000064:	eb000036 	bl	40000144 <beep_off>
40000068:	eafffff9 	b	40000054 <main+0xc>

4000006c <pwm_init>:
4000006c:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
40000070:	e28db000 	add	fp, sp, #0
40000074:	e59f3090 	ldr	r3, [pc, #144]	; 4000010c <pwm_init+0xa0>
40000078:	e59f208c 	ldr	r2, [pc, #140]	; 4000010c <pwm_init+0xa0>
4000007c:	e5922000 	ldr	r2, [r2]
40000080:	e3c2200f 	bic	r2, r2, #15
40000084:	e3822002 	orr	r2, r2, #2
40000088:	e5832000 	str	r2, [r3]
4000008c:	e59f3078 	ldr	r3, [pc, #120]	; 4000010c <pwm_init+0xa0>
40000090:	e59f2074 	ldr	r2, [pc, #116]	; 4000010c <pwm_init+0xa0>
40000094:	e5922008 	ldr	r2, [r2, #8]
40000098:	e3c2200f 	bic	r2, r2, #15
4000009c:	e5832008 	str	r2, [r3, #8]
400000a0:	e59f3068 	ldr	r3, [pc, #104]	; 40000110 <pwm_init+0xa4>
400000a4:	e59f2064 	ldr	r2, [pc, #100]	; 40000110 <pwm_init+0xa4>
400000a8:	e5922000 	ldr	r2, [r2]
400000ac:	e3c220ff 	bic	r2, r2, #255	; 0xff
400000b0:	e38220f9 	orr	r2, r2, #249	; 0xf9
400000b4:	e5832000 	str	r2, [r3]
400000b8:	e59f3050 	ldr	r3, [pc, #80]	; 40000110 <pwm_init+0xa4>
400000bc:	e59f204c 	ldr	r2, [pc, #76]	; 40000110 <pwm_init+0xa4>
400000c0:	e5922004 	ldr	r2, [r2, #4]
400000c4:	e3c2200f 	bic	r2, r2, #15
400000c8:	e3822002 	orr	r2, r2, #2
400000cc:	e5832004 	str	r2, [r3, #4]
400000d0:	e59f3038 	ldr	r3, [pc, #56]	; 40000110 <pwm_init+0xa4>
400000d4:	e3a02032 	mov	r2, #50	; 0x32
400000d8:	e5832010 	str	r2, [r3, #16]
400000dc:	e59f302c 	ldr	r3, [pc, #44]	; 40000110 <pwm_init+0xa4>
400000e0:	e3a02064 	mov	r2, #100	; 0x64
400000e4:	e583200c 	str	r2, [r3, #12]
400000e8:	e59f3020 	ldr	r3, [pc, #32]	; 40000110 <pwm_init+0xa4>
400000ec:	e59f201c 	ldr	r2, [pc, #28]	; 40000110 <pwm_init+0xa4>
400000f0:	e5922008 	ldr	r2, [r2, #8]
400000f4:	e3c220ff 	bic	r2, r2, #255	; 0xff
400000f8:	e3822003 	orr	r2, r2, #3
400000fc:	e5832008 	str	r2, [r3, #8]
40000100:	e28bd000 	add	sp, fp, #0
40000104:	e8bd0800 	ldmfd	sp!, {fp}
40000108:	e12fff1e 	bx	lr
4000010c:	114000a0 	.word	0x114000a0
40000110:	139d0000 	.word	0x139d0000

40000114 <beep_on>:
40000114:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
40000118:	e28db000 	add	fp, sp, #0
4000011c:	e59f301c 	ldr	r3, [pc, #28]	; 40000140 <beep_on+0x2c>
40000120:	e59f2018 	ldr	r2, [pc, #24]	; 40000140 <beep_on+0x2c>
40000124:	e5922008 	ldr	r2, [r2, #8]
40000128:	e3c220ff 	bic	r2, r2, #255	; 0xff
4000012c:	e3822009 	orr	r2, r2, #9
40000130:	e5832008 	str	r2, [r3, #8]
40000134:	e28bd000 	add	sp, fp, #0
40000138:	e8bd0800 	ldmfd	sp!, {fp}
4000013c:	e12fff1e 	bx	lr
40000140:	139d0000 	.word	0x139d0000

40000144 <beep_off>:
40000144:	e52db004 	push	{fp}		; (str fp, [sp, #-4]!)
40000148:	e28db000 	add	fp, sp, #0
4000014c:	e59f3018 	ldr	r3, [pc, #24]	; 4000016c <beep_off+0x28>
40000150:	e59f2014 	ldr	r2, [pc, #20]	; 4000016c <beep_off+0x28>
40000154:	e5922008 	ldr	r2, [r2, #8]
40000158:	e3c22001 	bic	r2, r2, #1
4000015c:	e5832008 	str	r2, [r3, #8]
40000160:	e28bd000 	add	sp, fp, #0
40000164:	e8bd0800 	ldmfd	sp!, {fp}
40000168:	e12fff1e 	bx	lr
4000016c:	139d0000 	.word	0x139d0000
