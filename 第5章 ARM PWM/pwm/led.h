#ifndef LED_H
#define LED_H

struct exynos4412_GPIO {

	unsigned int CON;
	unsigned int DAT;
	unsigned int PUD;
	unsigned int DRV;
};

#define GPX1_ADDR ((volatile struct exynos4412_GPIO *)0x11000C20)
#define GPX1 (*GPX1_ADDR)

#define GPX2_ADDR ((volatile struct exynos4412_GPIO *)0x11000C40)
#define GPX2 (*GPX2_ADDR)

#define GPF3_ADDR ((volatile struct exynos4412_GPIO *)0x114001E0)
#define GPF3 (*GPF3_ADDR)

void led2_init(void);
void led2_on(void);
void led2_off(void);
void led3_init(void);
void led3_on(void);
void led3_off(void);
void led4_init(void);
void led4_on(void);
void led4_off(void);
void led5_init(void);
void led5_on(void);
void led5_off(void);

#endif
