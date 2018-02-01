/**
  ******************************************************************************
  * @file    main.c
  * @author  Bruceou
  * @version V1.0
  * @date    2018-2
  * @brief   This example describes how to use GPIO conversion
  ******************************************************************************
  */
/**Includes*********************************************************************/
#include "exynos_4412.h"  
#include "led.h"  

int main (void)  
{  
    int i = 0;  
    led_init ();  
	while (1) 
	{  
        led_on(i%4);  
        led_off((i-1+4)%4);  
        i++;  
        delay_ms(500);  
    }  
   return 0;  
} 


