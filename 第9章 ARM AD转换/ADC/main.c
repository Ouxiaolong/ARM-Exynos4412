/*
 *@brief	This example describes how to use ADC conversion
 *@date:	12. June. 2014
 *@author	liujh@farsight.com.cn
 *@Contact 	Us: http://dev.hqyj.com
 *Copyright(C) 2014, Farsight
*/

#include "exynos_4412.h"
#include "uart.h"

/*
 *If A/D conversion start by read
 * */
//#define __READ_START_

/**********************************************************************
 * @brief		mydelay_ms program body
 * @param[in]	int (ms)
 * @return 		None
 **********************************************************************/
void mydelay_ms(int time)
{
	int i, j;
	while(time--)
	{
		for (i = 0; i < 5; i++)
			for (j = 0; j < 514; j++);
	}
}

/*-------------------------MAIN FUNCTION------------------------------*/
/**********************************************************************
 * @brief		Main program body
 * @param[in]	None
 * @return 		int
 **********************************************************************/
int main(void)
{
	unsigned int  temp_adc = 0, temp_mv;

	GPX2.CON = 0x1 << 28;//GPX2CON[7]: Output drive LED

	uart_init();


	ADC_CFG &= ~(0x1 << 16); //Bit_16:Select ADC Mux 0:General 1:MTCADC

	ADCMUX = 0x3;	//0x3: 0011 = AIN3

#ifdef	__READ_START_
	//12bit A/D conversion; enable A/D converter prescaler; prescaler value:255; A/D conversion start by read
	ADCCON = (0x1<<16) | (0x1<<14) | (0xff<<6) | 0x1<<1;
#else
	//12bit A/D conversion; enable A/D converter prescaler; prescaler value:255
	ADCCON = (0x1<<16) | (0x1<<14) | (0xff<<6);
#endif

#ifdef	 __READ_START_
	temp_adc = ADCDAT & 0xfff;
#endif

	printf("\n************ ADC test ************\n");

	while(1)
	{
			//Turn on LED
			GPX2.DAT |= 0x1 << 7;

#ifndef	__READ_START_
			ADCCON |= 0x1;//start ADC conversion
#endif
			mydelay_ms(100);

			while(!(ADCCON & (0x1<<15)));

			temp_adc = ADCDAT & 0xfff;

			temp_mv = 1800 * temp_adc / 4095;

			printf("adc value: %d mv\n", temp_mv);

			mydelay_ms(500);

			//Turn off LED
			GPX2.DAT &= ~(0x1 << 7);
			mydelay_ms(500);
		}
	return 0;
}
