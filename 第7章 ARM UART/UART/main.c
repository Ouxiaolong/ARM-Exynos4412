/**
  ******************************************************************************
  * @file    main.c
  * @author  Bruceou
  * @version V1.0
  * @date    2018-2
  * @brief   This example describes how to use UART conversion
  ******************************************************************************
  */
/**Includes*********************************************************************/
#include "led.h"
#include "uart.h"
#include "beep.h"
#include "pwm.h"

int main (void)  
{  
	int count =10;
	int compare =100;
    char ch[20];  
    pwm_init();  
    led_init();
	beep_init();
	uart2_init();
	pwm_cycle(count ,compare);
    char *q = "hello UART!";  
    puts(q);  
    while(1)  
    {  
        gets(ch);  
        puts(ch);  
        if(!strcmp(ch, "beep_on\n")) 
		{
			if(count = 100)
			{
				count =0;
			}
			count +=5;
			pwm_cycle(count ,compare);
			led_on(1);
			beep_on();
		}
        if(!strcmp(ch, "beep_off\n"))  
        {
			led_off(1);
			beep_off();
		}
    }  
   return 0;  
}  
