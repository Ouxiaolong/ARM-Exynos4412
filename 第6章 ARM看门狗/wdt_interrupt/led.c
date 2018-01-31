#include "led.h"

/*
LED3: GPX1_0: 0x1100_0C20
LED2: GPX2_7: 0x1100_0C40
LED4: GPF3_4: 0x1140_01E0
LED5: GPF3_5: 0x1140_01E0
*/
void led4_init(void)
{
	GPF3.CON = (GPF3.CON & ~(0xf<<16)) | (0x1 << 16);
}

void led4_on(void)
{
	GPF3.DAT |= 0x1 << 4;
}

void led4_off(void)
{
	GPF3.DAT &= ~(0x1 << 4);
}

void led5_init(void)
{
	GPF3.CON = (GPF3.CON & ~(0xf<<20)) | (0x1 << 20);
}

void led5_on(void)
{
	GPF3.DAT |= 0x1 << 5;
}

void led5_off(void)
{
	GPF3.DAT &= ~(0x1 << 5);
}

void led2_init(void)
{
	GPX2.CON = (GPX2.CON & ~(0xf<<28)) | (0x1 << 28);
}

void led2_on(void)
{
	GPX2.DAT |= 0x1 << 7;
}

void led2_off(void)
{
	GPX2.DAT &= ~(0x1 << 7);
}

void led3_init(void)
{
	GPX1.CON &= ~0xf;
	GPX1.CON |= 0x1;
}

void led3_on(void)
{
	GPX1.DAT |= 0x1;
}

void led3_off(void)
{
	GPX1.DAT &= ~0x1;
}

