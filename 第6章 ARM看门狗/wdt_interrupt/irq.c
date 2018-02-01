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
#include "exynos4412.h"
#include "irq.h"
#include "wdt.h"
#include "uart.h"

#define EINVAL 1

#define DEFAULT_MAX_IRQ 160
#define CPU_TARGET_MASK 0xF

static void key2_gpio_conf(void)
{
	//Key_2  Interrupt  GPX1_1
	GPX1.PUD = GPX1.PUD & ~(0x3 << 2); // Disables Pull-up/Pull-down
	GPX1.CON = (GPX1.CON & ~(0xF << 4)) | (0xF << 4); //GPX1_1: WAKEUP_INT1[1](EXT_INT41[1])
	EXT_INT41_CON = (EXT_INT41_CON & ~(0x7 << 4)) | 0x2 << 4;
	EXT_INT41_MASK = (EXT_INT41_MASK & ~(0x1 << 1)); //  Bit: 1 = Enables interrupt
}

static void key2_gpio_clear_pending(void)
{
	EXT_INT41_PEND |= 0x1 << 1;
}

static void key3_gpio_conf(void)
{
	// Key3 GPX1_1 GPX1CON [11:8] = 0xF
	GPX1.CON |= (0xF << 8); // ID = 58
	GPX1.PUD = GPX1.PUD & ~(0x3 << 4); // Disable Pull-up/ Pull-down
	EXT_INT41_CON = (EXT_INT41_CON & ~(0x7 << 8)) | (0x2<<8); // Low Level 
	EXT_INT41_MASK &= ~(0x1 << 2); // Enable EINT10
}

static void key3_gpio_clear_pending(void)
{
	EXT_INT41_PEND |= 0x1 << 2;
}

// cpu: 0x1, 0x2, 0x4, 0x8, priority: [0x0, 0xFF]
// irq_num: [0, 159]
int gic_init_irq_by_nr(int irq_num, int cpu, int priority)
{
	unsigned int sel;
	unsigned int off;

	unsigned int *icd_ipr_addr = (void *)&ICDIPR; // Priority
	unsigned int *icd_iptr_addr = (void *)&ICDIPTR; // CPU Target
	unsigned int *icd_iser_addr = (void *)&ICDISER; // Set-Enable

	if(irq_num < 0) return -EINVAL;
	if(irq_num > DEFAULT_MAX_IRQ) return -EINVAL;

	sel = (unsigned int)irq_num / 4;
	off = (unsigned int)irq_num % 4;
	off <<= 3;

	// CPU Target
	icd_iptr_addr += sel;
	*icd_iptr_addr |= ( (cpu & CPU_TARGET_MASK) << off);

	// INT Priority
	icd_ipr_addr += sel;
	*icd_ipr_addr = ( (*icd_ipr_addr) & ~(0xFF<<off))
			| ( (priority & 0xFF) << off);


	sel = (unsigned int)irq_num / 32;
	off = (unsigned int)irq_num % 32;
	// Set-Enable
	icd_iser_addr += sel;
	*icd_iser_addr |= 0x1 << off;

	return 0;
}

static int gic_cpu0_enable_with_mask(int mask)
{
	CPU0.ICCICR |= 0x1; //Global enable for signaling of interrupts
	ICDDCR = 0x1; // Bit1: GIC monitors the peripheral interrupt signals and
			// forwards pending interrupts to the CPU interfaces2
	CPU0.ICCPMR = (mask & 0xFF); //The priority mask level.Priority filter. threshold

	return 0;
}


static int gic_cpu0_get_irq_id(void)
{
	return (CPU0.ICCIAR & 0x3FF);
}

static int gic_cpu0_clear_pending(int irq_num)
{
	unsigned int sel;
	unsigned int off;

	if(irq_num < 0) return -EINVAL;
	if(irq_num > DEFAULT_MAX_IRQ) return -EINVAL;

	unsigned int *icd_icpr_addr = (void *)&ICDICPR;
	sel = (unsigned int)irq_num / 32;
	off = (unsigned int)irq_num % 32;

	icd_icpr_addr += sel;
	*icd_icpr_addr |= 0x1<<off;

	return 0;
}
static int gic_cpu0_eoi(int irq_num)
{
	CPU0.ICCEOIR = (CPU0.ICCEOIR & ~(0x3FF)) | irq_num;
	return 0;
}


void irq_init(void)
{
	gic_cpu0_enable_with_mask(255);
	gic_init_irq_by_nr(57, 1, 0);// priority = 0, to cpu 0
	gic_init_irq_by_nr(58, 1, 4);// priority = 4, to cpu 0

	key2_gpio_conf();
	key3_gpio_conf();
}

int do_irq()
{
	int id = gic_cpu0_get_irq_id();
	switch (id) {
		case 57: 
			puts("ID 57 Interrupted ...\r\n");
			key2_gpio_clear_pending();
			break;
		case 58: 
			puts("ID 58 Interrupted ...\r\n");
			key3_gpio_clear_pending();
			break;
		case 75:
			wdt_handler();
			wdt_clear_pending();
			break;
		default:
			printf("Unkown Interrupted ID = %d ...\r\n", id);
			break;
	}

	gic_cpu0_clear_pending(id);
	gic_cpu0_eoi(id);
	
	return 0;
}
