/**
  ******************************************************************************
  * @file    led.c
  * @author  Bruceou
  * @version V1.0
  * @date    2018-2
  * @brief   led api
  ******************************************************************************
  */
/**Includes*********************************************************************/
#include "led.h"
#include "pwm.h"

/*
LED3: GPX1_0: 0x1100_0C20
LED2: GPX2_7: 0x1100_0C40
*/

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

