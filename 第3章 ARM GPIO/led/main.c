/*************************************************************************
    > File Name: main.c
    > Author: 龙创科技
    > Mail: ouxiaolong88@163.com 
    > Created Time: 2016年07月17日 星期日 10时14分44秒
 ************************************************************************/

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


