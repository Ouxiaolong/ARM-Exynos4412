/**
  ******************************************************************************
  * @file    main.c
  * @author  Bruceou
  * @version V1.0
  * @date    2018-2
  * @brief   This example describes how to use RTC function
  ******************************************************************************
  */
/**Includes*********************************************************************/
#include "exynos_4412.h"
#include "uart.h"

/*
 * Irq_rutine
 * */
void do_irq() {

}

/**
  * @brief		mydelay_ms program body
  * @param[in]	int (ms)
  * @return 		None
  */
void mydelay_ms(int time)
{
	int i, j;
	while(time--)
	{
		for (i = 0; i < 5; i++)
			for (j = 0; j < 514; j++);
	}
}

/**
  * @brief		RTC_init, second, minute, hour, day, week, month, year
  * @param[in]	None
  * @return 		None
  */
void RTC_init()
{
	RTCCON = 0x1;	// Enables RTC control

	RTC.BCDSEC = 0x11;
	RTC.BCDMIN = 0x11;
	RTC.BCDHOUR = 0x11;
	RTC.BCDDAY = 0x11;
	RTC.BCDWEEK = 0x11;
	RTC.BCDMON = 0x11;
	RTC.BCDYEAR = 0x11;

	RTCCON = 0x0;	// Disables RTC control

}

/*-------------------------MAIN FUNCTION------------------------------*/
/**
  * @brief		Main program body
  * @param[in]	None
  * @return 		int
  */
int main(void)
{
	GPX2.CON = 0x1 << 28;
	uart_init();

	RTC_init();

	printf("\n****** RTC ******* \n");

	while(1)
		{
			//Turn on
			GPX2.DAT = GPX2.DAT | 0x1 << 7;
			mydelay_ms(500);

			printf("year 20%x : month %x : date %x :day %x ", RTC.BCDYEAR,\
														    RTC.BCDMON,\
														    RTC.BCDDAY,\
														    RTC.BCDWEEK );

			printf("hour %x : min %x : sec %x\n",RTC.BCDHOUR, RTC.BCDMIN, RTC.BCDSEC);
			//Turn off
			GPX2.DAT = GPX2.DAT & ~(0x1 << 7);
			mydelay_ms(500);
		}
	return 0;
}
