
#ifndef _BEEP_H_
#define _BEEP_H_

struct exynos4412_BEEP {

	unsigned int CON;
	unsigned int DAT;
	unsigned int PUD;
	unsigned int DRV;
};

#define BEEP_ADDR ((volatile struct exynos4412_BEEP *)0x114000A0)
#define GPD0 (*BEEP_ADDR)

void beep_init(void);


#endif
