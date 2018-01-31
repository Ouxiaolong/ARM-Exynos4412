/*************************************************************************
    > File Name: main.c
    > Author: 龙创科技
    > Mail: ouxiaolong88@163.com 
    > Created Time: 2016年07月17日 星期日 10时14分31秒
 ************************************************************************/
#include "exynos_4412.h"  
#include "led.h"   

/* 
 *  裸机代码，不同于LINUX 应用层， 一定加循环控制 
 */  
int main (void)  
{  
    GPX1.CON =GPX1.CON & (~(0xf << 4)) |(0xf << 4); //配置引脚功能为外部中断  
    GPX1.PUD = GPX1.PUD & (~(0x3 << 2));  //关闭上下拉电阻  
    EXT_INT41_CON = EXT_INT41_CON &(~(0xf << 4))|(0x2 << 4); //外部中断触发方式  
    EXT_INT41_MASK = EXT_INT41_MASK & (~(0x1 << 1));  //使能中断  
    ICDDCR = 1;  //使能分配器  
    ICDISER.ICDISER1 = ICDISER.ICDISER1 | (0x1 << 25); //使能相应中断到分配器  
    ICDIPTR.ICDIPTR14 = ICDIPTR.ICDIPTR14 & (~(0xff << 8))|(0x1 << 8); //选择CPU接口  
    CPU0.ICCPMR = 255; //中断屏蔽优先级  
    CPU0.ICCICR = 1;   //使能中断到CPU  
    led_init();  
    while(1)  
    {  
  
    }  
   return 0;  
}  

