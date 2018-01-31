#ifndef UART_H
#define UART_H


void uart2_init(void);
int uart2_getc(void);
int uart2_putc(int ch);
static inline int getc(void)
{
	return  uart2_getc();
}
static inline int putchar(int ch)
{
	return uart2_putc(ch);
}
int puts(const char *str);
void gets(char *p);
int strcmp(const char *src, const char *des);  

#endif
