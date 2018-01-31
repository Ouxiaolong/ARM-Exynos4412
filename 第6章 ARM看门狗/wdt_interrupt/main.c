#include "led.h"
#include "uart.h"

void __delay(void);

int main()
{
	// May Be Called By SVC Mode
	// Init: Key2 Key3 
	irq_init();

	
	wdt_init_interrupt(255, 0);
	wdt_start_interrupt(0x3FFFF);
	gic_init_irq_by_nr(75, 1, 0);// ID = 75, To CPU0, Priority = 0


	int cnt = 0;
	while(1) {
		printf("hello world %d...\r\n", ++cnt);

		led5_off();
		led2_on();
		__delay();
		__delay();

		led2_off();
		led5_on();
		__delay();
		__delay();

		// led5_off();
		// led2_on();
		// __delay();
	}
	return 0;
}
