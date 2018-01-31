#include "exynos_4412.h"

void uart_init()
{

	/*UART2 initialize*/
	GPA1.CON = (GPA1.CON & ~0xFF ) | (0x22); //GPA1_0:RX;GPA1_1:TX

	UART2.ULCON2 = 0x3; //Normal mode, No parity,One stop bit,8 data bits
	UART2.UCON2 = 0x5;  //Interrupt request or polling mode
	//Baud-rate : src_clock:100Mhz
	UART2.UBRDIV2 = 0x35;
	UART2.UFRACVAL2 = 0x5;
}

void putc(const char data)
{
	while(!(UART2.UTRSTAT2 & 0X2));
	UART2.UTXH2 = data;
	if (data == '\n')
			putc('\r');
}
void puts(const  char  *pstr)
{
	while(*pstr != '\0')
		putc(*pstr++);
}
