/**
  ******************************************************************************
  * @file    pwm.c
  * @author  Bruceou
  * @version V1.0
  * @date    2018-2
  * @brief   pwm api
  ******************************************************************************
  */
/**Includes*********************************************************************/
#include "pwm.h"
#include "beep.h"

void pwm_init(void)
{
	PWM.TCFG0 =PWM.TCFG0 &(~(0XFF))|0XF9;
	PWM.TCFG1 =PWM.TCFG1 &(~(0XF))|0X2;
	PWM.TCON = PWM.TCON &(~(0XFF))|(1<<1)|(1<<0)|(1<<4);
}

void pwm_cycle(int count ,int compare)
{
	PWM.TCMPB0 =count;
	PWM.TCNTB0 =compare;
	PWM.TCON = PWM.TCON &(~(0XFF))|(1<<1)|(1<<0);
}

void beep_on(void)
{
	PWM.TCON =PWM.TCON &(~(0XFF))|(1<<0)|(1<<3);
}

void beep_off()
{
	PWM.TCON =PWM.TCON &(~(1<<0));
}

