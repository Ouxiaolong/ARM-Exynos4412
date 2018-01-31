/*************************************************************************
    > File Name: led.c
    > Author: 龙创科技
    > Mail: ouxiaolong88@163.com 
    > Created Time: 2016年07月17日 星期日 10时14分31秒
 ************************************************************************/

#include "exynos_4412.h"  
#include "led.h"  

void led_init(void)  
{  
    GPX2.CON = GPX2.CON & (~(0xf0000000)) | 0x10000000;  
    GPX1.CON = GPX1.CON & (~(0x0000000f)) | 0x00000001;  
    GPF3.CON = GPF3.CON & (~(0x000f0000)) | 0x00010000;  
    GPF3.CON = GPF3.CON & (~(0x00f00000)) | 0x00100000;  
}  
void led_on(int n)  
{  
    switch(n)  
    {  
        case 0:  
            GPX2.DAT = GPX2.DAT|0x80;  
            break;  
        case 1:  
            GPX1.DAT = GPX1.DAT|0x01;  
            break;  
        case 2:  
            GPF3.DAT = GPF3.DAT|0x10;  
            break;  
        case 3:  
            GPF3.DAT = GPF3.DAT|0x20;  
            break;  
    }  
}  
void led_off(int n)  
{  
    switch(n)  
    {  
        case 0:  
            GPX2.DAT = GPX2.DAT&(~(0x80));  
            break;  
        case 1:  
            GPX1.DAT = GPX1.DAT&(~(0x01));  
            break;  
        case 2:  
            GPF3.DAT = GPF3.DAT&(~(0x10));  
            break;  
        case 3:  
            GPF3.DAT = GPF3.DAT&(~(0x20));  
            break;  
    }  
}  

void  delay_ms(unsigned int num)  
{  
    int i,j;  
    for(i=num; i>0;i--)  
    for(j=1000;j>0;j--)  
        ;  
} 

