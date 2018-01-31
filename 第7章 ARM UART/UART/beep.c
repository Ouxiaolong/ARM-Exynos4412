/*************************************************************************
    > File Name: beep.c
    > Author: 龙创科技
    > Mail: ouxiaolong88@163.com 
    > Created Time: 2016年05月03日 星期二 20时24分27秒
 ************************************************************************/
#include "beep.h"

void beep_init(void)
{
	GPD0.CON = GPD0.CON &(~(0XF))|0X2;
	GPD0.PUD = GPD0.PUD &(~(0XF));
}
