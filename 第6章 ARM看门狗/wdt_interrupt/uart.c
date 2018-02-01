/**
  ******************************************************************************
  * @file    uart.c
  * @author  Bruceou
  * @version V1.0
  * @date    2018-2
  * @brief   uart api
  ******************************************************************************
  */
/**Includes*********************************************************************/
#include "exynos4412.h"
#include "uart.h"

void uart2_gpio_conf(void)
{
	GPA1.CON = (GPA1.CON & ~0xff) | 0x22;
}

void uart2_init(void)
{
	unsigned int conf = 0;
	uart2_gpio_conf();

	conf = (0x3<<0);

	UART2.ULCON2 = (UART2.ULCON2 & ~0xFF) | (conf & 0xFF);

	UART2.UBRDIV2 = 53;
	UART2.UFRACVAL2 = 5;
}

int uart2_getc(void)
{
	int ch;
	/*
	while(1) {
		if(UART2.UTRSTAT2 & 0x1) break;
	}
	*/
	while( !(UART2.UTRSTAT2 & 0x1));

	ch = UART2.URXH2 & 0xFF;

	return ch;
}

int uart2_putc(int ch)
{
	while( !(UART2.UTRSTAT2 & 0x2));
	UART2.UTXH2 = ch & 0xFF;

	return ch & 0xFF;
}

int puts(const char *str)
{
	int cnt = 0;
	while(*str) {
		putchar(*str);

		++str;
		++cnt;
	}

	return cnt;
}
