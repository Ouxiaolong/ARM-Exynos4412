// Exynos-4412 
#include "led.h"
#include "pwm.h"
#include "beep.h"

void __delay(void);

void main(void)
{
	int count =10;
	int compare =100;

	led2_init();
	beep_init();
	pwm_init();
	pwm_cycle(count ,compare);

	while(1)
	{
		if(count = 100)
		{
			count =0;
		}
		count +=5;
		pwm_cycle(count ,compare);
		led2_on();
		beep_on();
		__delay();

		led2_off();
		beep_off();
		__delay();

		led2_on();
		beep_off();
	}
}


