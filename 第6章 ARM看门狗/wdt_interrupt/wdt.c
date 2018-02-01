/**
  ******************************************************************************
  * @file    wdt.c
  * @author  Bruceou
  * @version V1.0
  * @date    2018-2
  * @brief   wdt api
  ******************************************************************************
  */
/**Includes*********************************************************************/
#include "exynos4412.h"

int wdt_init_interrupt(int prescaler, int select)
{
	unsigned int WTCON = WDT.WTCON;
	WTCON &= (~(0xFF<<8)) & (~(0x3 << 3));

	// Disable Reset, Disable Interrupt, Disable WDT Timer
	WTCON &= (~(0x1<<0)) & (~(0x1<<2)) & (~(0x1<<5));

	WTCON |= ((prescaler & 0x0FF)<<8) | ((select & 0x3) << 3);

	WDT.WTCON = WTCON;
}

int wdt_start_interrupt(int timeout)
{
	WDT.WTDAT = timeout;
	WDT.WTCNT = timeout;

#if 1
	// Enable Interrupt, Enable WDT Timer
	WDT.WTCON &= ~(0x1<<0); // De-Assert Reset
	WDT.WTCON |= (0x1<<2)  | (0x1<<5);
#else
	WDT.WTCON |= (0x1<<0)  | (0x1<<5);
#endif
}

int wdt_clear_pending()
{
	WDT.WTCLRINT = 0x1;
}

int wdt_handler()
{
	puts("WDT Interrupt ...\r\n");
}
