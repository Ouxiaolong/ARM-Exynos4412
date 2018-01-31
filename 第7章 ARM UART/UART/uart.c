/*************************************************************************
    > File Name: uart.c
    > Author: 龙创科技
    > Mail: ouxiaolong88@163.com 
    > Created Time: 2016年05月03日 星期二 20时25分02秒
 ************************************************************************/
#include "exynos_4412.h"
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
#if 0
void putc(const char data)  
{  
    while(!(UART0.UTRSTAT0 & 0X2));  
    UART0.UTXH0 = data;  
    if (data == '\n')  
            putc('\r');  
}  
char getc(void)  
{  
    char data;  
    while(!(UART0.UTRSTAT0 & 0x1));  
    data = UART0.URXH0;  
    if ((data == '\n') || (data == '\r'))  
    {  
        putc('\n');  
        putc('\r');  
    }  
    else  
        putc(data);  
  
    return data;  
}  
#endif
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
#if 0
void puts(const  char  *str)  
{  
    while(*str != '\0')  
        putc(*str++);  
}  
#endif
  
void gets(char *p)  
{  
    char data;  
    while((data = getc())!= '\r')  
        *p++ = data;  
    if(data == '\r')  
        *p++ = '\r';  
    *p = '\0';  
}  

int strcmp(const char *src, const char *des)  
{  
    while(*src || *des)  
    {  
        if(*src > *des)  
            return 1;  
        else if(*src < *des)  
            return -1;  
        else  
        {  
            src++;  
            des++;  
        }  
    }  
    return 0;  
}  
  

