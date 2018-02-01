/**
  ******************************************************************************
  * @file    irq.c
  * @author  Bruceou
  * @version V1.0
  * @date    2018-2
  * @brief   irq api
  ******************************************************************************
  */
/**Includes*********************************************************************/
#include "exynos_4412.h"
#include "led.h"

/* 中断处理:
 * <1> IRQ模式: 中断irq引脚, 中断GIC
 * <2> GIC中断：中断号ID
 *      Key2: GPX1_1/XEINT9
 *      (1) Page 752: EINT9  ---> 中断ID: 57
 *      (2) GPX1_1 配置成中断功能: 0xF
 *      (3) GPX1_1 禁止上拉和下拉 PUD[3:2]
 *      (4) EXT_INT41CON[1] : 0x2 ---> 下降沿触发中断falling edge
 *      (5) EXT_INT41_MASK[1]: 0x0 ---> Enables Interrupt
 * <3> GIC 配置: 
 *      (1) ICCICR_CPU0[0] : 0x1048_0000 :   1 ---> enable
 *      (2) ICDDCR:   0x1049_0000 :  1 ---> enable
 *      (3) ICCPMR_CPU0[7:0]:  0x1048_004 :  255屏蔽优先级
 *           ICDIPR_CPU0  偏移57个字节(每个中断占一个字节), 默认0，最高优先级
 *      (4) ICCIAR_CPU0[9:0]: 0x1048_000C:  中断ID
 *      (5) 结束中断
 *      (6) ICDISER_CPU0[57]:   Set-Enable Interrupt 1
 *      (7)  ICDIPTR_CPU:   选择该中断递送给哪一个CPU
 * 
 * <4> 中断清除
 *      (1) EXT_INT41_PEND[1]:  0
 *      (2)  (4) ICCICPR_CPU0
 *      (3)  (5) ICCEOIR_CPU0[9:0]: 0x1048_0010: 回写ID给GIC
 */

void irq_init()
{

	//Key_2  Interrupt  GPX1_1
	GPX1.PUD = GPX1.PUD & ~(0x3 << 2); // Disables Pull-up/Pull-down
	GPX1.CON = (GPX1.CON & ~(0xF << 4)) | (0xF << 4); //GPX1_1: WAKEUP_INT1[1](EXT_INT41[1])
	EXT_INT41_CON = (EXT_INT41_CON & ~(0x7 << 4)) | 0x2 << 4;
	EXT_INT41_MASK = (EXT_INT41_MASK & ~(0x1 << 1)); //  Bit: 1 = Enables interrupt

	/*
	 * GIC interrupt controller:
	 */
	// Enables the corresponding interrupt SPI25, SPI26 -- Key_2, Key_3
	ICDISER.ICDISER1 |= (0x1 << 25) | (0x1 << 26);
	CPU0.ICCICR |= 0x1; //Global enable for signaling of interrupts
	CPU0.ICCPMR = 0xFF; //The priority mask level.Priority filter. threshold
	ICDDCR = 1;		//Bit1:  GIC monitors the peripheral interrupt signals and
					//		forwards pending interrupts to the CPU interfaces2

	ICDIPTR.ICDIPTR14 = 0x01010101;	//SPI25  SPI26  interrupts are sent to processor 0


}
#if 0
void do_irq(void)
{
	int irq_num;
	irq_num = (CPU0.ICCIAR & 0x1FF);

	switch (irq_num) 
	{
		case 57: //Turn on Led3; Turn off Led2

		//Clear Pend
		EXT_INT41_PEND |= 0x1 << 1;
		ICDICPR.ICDICPR1 |= 0x1 << 26;
		break;
		default: break;
	}

	// End of interrupt
	CPU0.ICCEOIR = (CPU0.ICCEOIR & ~(0x1FF)) | irq_num;
}
#endif
#if 1
void do_irq(void)  
{  
    static int a = 1;  
    int irq_num;  
    irq_num = CPU0.ICCIAR&0x3ff;  //获取中断号  
    switch(irq_num)  
    {  
    case 57:  
        //printf("in the irq_handler\n");  
            if(a)  
                led_on(1);  
            else  
                led_off(1);  
            a = !a;  
            EXT_INT41_PEND = EXT_INT41_PEND |((0x1 << 1)); //清GPIO中断标志位  
            ICDICPR.ICDICPR1 = ICDICPR.ICDICPR1 | (0x1 << 25); //清GIC中断标志位  
        break;  
    }  
    CPU0.ICCEOIR = CPU0.ICCEOIR&(~(0x3ff))|irq_num; //清cpu中断标志位  
}  
#endif