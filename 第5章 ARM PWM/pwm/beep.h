/*************************************************************************
    > File Name: beep.h
    > Author: 龙创科技
    > Mail: ouxiaolong88@163.com 
    > Created Time: 2016年05月03日 星期二 20时25分02秒
 ************************************************************************/

#ifndef _BEEP_H_
#define _BEEP_H_

struct exynos4412_BEEP {

	unsigned int CON;
	unsigned int DAT;
	unsigned int PUD;
	unsigned int DRV;
};

#define BEEP_ADDR ((volatile struct exynos4412_BEEP *)0x114000A0)
#define GPD0 (*BEEP_ADDR)

void beep_init(void);


#endif
