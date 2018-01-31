#ifndef _PWM_H_
#define _PWM_H_

struct exynos4412_PWM{
	unsigned int TCFG0;
	unsigned int TCFG1;
	unsigned int TCON;
	unsigned int TCNTB0;
	unsigned int TCMPB0;
	unsigned int TCNTO0;
	unsigned int TCNTB1;
	unsigned int TCMPB1;
	unsigned int TCNTO1;
	unsigned int TCNTB2;
	unsigned int TCMPB2;
	unsigned int TCNTO2;
	unsigned int TCNTB3;
	unsigned int TCMPB3;
	unsigned int TCNTO3;
	unsigned int TCMPB4;
	unsigned int TCNTO4;
	unsigned int TINT_CSTAT;
};

#define PWM_ADDR ((volatile struct exynos4412_PWM*)0X139D0000)
#define PWM  (*PWM_ADDR)

void pwm_init(void);
void pwm_cycle(int count ,int compare);
void beep_on(void);
void beep_off(void);

#endif

