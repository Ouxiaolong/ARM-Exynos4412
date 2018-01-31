#ifndef _UART_H
#define	_UART_H

void putc(const char data);
void puts(const  char  *pstr);
void uart_init(void);

extern void putc(const char data);
extern void puts(const  char  *pstr);
extern void uart_init(void);

#endif
