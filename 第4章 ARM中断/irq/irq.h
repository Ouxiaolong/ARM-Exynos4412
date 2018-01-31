#ifndef IRQ_H
#define IRQ_H

#define  	__REG(x)					(*(volatile unsigned int *)(x))  

#define		EXT_INT40_CON		__REG(0x11000E00)
#define		EXT_INT41_CON		__REG(0x11000E04)
#define		EXT_INT42_CON		__REG(0x11000E08)
#define		EXT_INT43_CON		__REG(0x11000E0C)

#define		EXT_INT40_FLTCON0	__REG(0x11000E80)
#define		EXT_INT40_FLTCON1	__REG(0x11000E84)
#define		EXT_INT41_FLTCON0	__REG(0x11000E88)
#define		EXT_INT41_FLTCON1	__REG(0x11000E8C)
#define		EXT_INT42_FLTCON0	__REG(0x11000E90)
#define		EXT_INT42_FLTCON1	__REG(0x11000E94)
#define		EXT_INT43_FLTCON0	__REG(0x11000E98)
#define		EXT_INT43_FLTCON1	__REG(0x11000E9C)

#define		EXT_INT40_MASK		__REG(0x11000F00)
#define		EXT_INT41_MASK		__REG(0x11000F04)
#define		EXT_INT42_MASK		__REG(0x11000F08)
#define		EXT_INT43_MASK		__REG(0x11000F0C)

#define		EXT_INT40_PEND		__REG(0x11000F40)
#define		EXT_INT41_PEND		__REG(0x11000F44)
#define		EXT_INT42_PEND		__REG(0x11000F48)
#define		EXT_INT43_PEND		__REG(0x11000F4C)


/* CPU0 */
typedef struct {
				unsigned int ICCICR;	//CPU interface control register
				unsigned int ICCPMR;
				unsigned int ICCBPR;
				unsigned int ICCIAR;	//Interrupt acknowledge register
				unsigned int ICCEOIR;
				unsigned int ICCRPR;	//Running priority register
				unsigned int ICCHPIR;
				unsigned int ICCABPR;
				unsigned int INTEG_EN;
				unsigned int INTERRUPT_OUT;
}cpu0;
#define CPU0 (* (volatile cpu0 *)0x10480000 )

#define ICCIIDR	__REG(0x104800FC)

/* CPU1 */
typedef struct {
				unsigned int ICCICR;
				unsigned int ICCPMR;
				unsigned int ICCBPR;
				unsigned int ICCIAR;
				unsigned int ICCEOIR;
				unsigned int ICCRPR;
				unsigned int ICCHPIR;
				unsigned int ICCABPR;
				unsigned int INTEG_EN;
				unsigned int INTERRUPT_OUT;
}cpu1;
#define CPU1 (* (volatile cpu1 *)0x10484000 )

/* CPU2 */
typedef struct {
				unsigned int ICCICR;
				unsigned int ICCPMR;
				unsigned int ICCBPR;
				unsigned int ICCIAR;
				unsigned int ICCEOIR;
				unsigned int ICCRPR;
				unsigned int ICCHPIR;
				unsigned int ICCABPR;
				unsigned int INTEG_EN;
				unsigned int INTERRUPT_OUT;
}cpu2;
#define CPU2 (* (volatile cpu2 *)0x10488000 )

/* CPU3 */
typedef struct {
				unsigned int ICCICR;
				unsigned int ICCPMR;
				unsigned int ICCBPR;
				unsigned int ICCIAR;
				unsigned int ICCEOIR;
				unsigned int ICCRPR;
				unsigned int ICCHPIR;
				unsigned int ICCABPR;
				unsigned int INTEG_EN;
				unsigned int INTERRUPT_OUT;
}cpu3;
#define CPU3 (* (volatile cpu3 *)0x1048C000 )

#define		ICDDCR		__REG(0X10490000)
#define		ICDICTR		__REG(0X10490004)
#define		ICDIIDR		__REG(0X10490008)

/* Interrupt security registers */
typedef struct {
				unsigned int ICDISR0_CPU0;
				unsigned int ICDISR1; // (SPI[31:0])
				unsigned int ICDISR2; // (SPI[63:32])
				unsigned int ICDISR3;
				unsigned int ICDISR4;
}isr;
#define ICDISR (* (volatile isr *)0x10490080 )

/* Interrupt set-enable register */
typedef struct {
				unsigned int ICDISER0_CPU0;
				unsigned int ICDISER1;	// (SPI[31:0])
				unsigned int ICDISER2;	// (SPI[63:32])
				unsigned int ICDISER3;
				unsigned int ICDISER4;
}iser;
#define ICDISER (* (volatile iser *)0x10490100 )

/* Interrupt clear-enable register */
typedef struct {
				unsigned int ICDICER0_CPU0;
				unsigned int ICDICER1;
				unsigned int ICDICER2;
				unsigned int ICDICER3;
				unsigned int ICDICER4;
}icer;
#define ICDICER (* (volatile icer *)0x10490180 )

/* Interrupt pending-set register */
typedef struct {
				unsigned int ICDISPR0_CPU0;
				unsigned int ICDISPR1; // (SPI[31:0])
				unsigned int ICDISPR2; // (SPI[63:32])
				unsigned int ICDISPR3;
				unsigned int ICDISPR4;
}ispr;
#define ICDISPR (* (volatile ispr *)0x10490200 )

/* Interrupt pending-clear register */
typedef struct {
				unsigned int ICDICPR0_CPU0;
				unsigned int ICDICPR1;
				unsigned int ICDICPR2;
				unsigned int ICDICPR3;
				unsigned int ICDICPR4;
}icpr;
#define ICDICPR (* (volatile icpr *)0x10490280 )

/* Active bit register */
typedef struct {
				unsigned int ICDABR0_CPU0;
				unsigned int ICDABR1;	// SPI 0 ~ 31
				unsigned int ICDABR2;	// SPI 32 ~ 63
				unsigned int ICDABR3;
				unsigned int ICDABR4;
}abr;
#define ICDABR (* (volatile abr *)0x10490300 )

/* Priority level register  */
typedef struct {
				unsigned int ICDIPR0_CPU0;
				unsigned int ICDIPR1_CPU0;
				unsigned int ICDIPR2_CPU0;
				unsigned int ICDIPR3_CPU0;
				unsigned int ICDIPR4_CPU0;
				unsigned int ICDIPR5_CPU0;
				unsigned int ICDIPR6_CPU0;
				unsigned int ICDIPR7_CPU0;
				unsigned int ICDIPR8;
				unsigned int ICDIPR9;
				unsigned int ICDIPR10;
				unsigned int ICDIPR11;
				unsigned int ICDIPR12;
				unsigned int ICDIPR13;
				unsigned int ICDIPR14;
				unsigned int ICDIPR15;
				unsigned int ICDIPR16;
				unsigned int ICDIPR17;
				unsigned int ICDIPR18;
				unsigned int ICDIPR19;
				unsigned int ICDIPR20;
				unsigned int ICDIPR21;
				unsigned int ICDIPR22;
				unsigned int ICDIPR23;
				unsigned int ICDIPR24;
				unsigned int ICDIPR25;
				unsigned int ICDIPR26;
				unsigned int ICDIPR27;
				unsigned int ICDIPR28;
				unsigned int ICDIPR29;
				unsigned int ICDIPR30;
				unsigned int ICDIPR31;
				unsigned int ICDIPR32;
				unsigned int ICDIPR33;
				unsigned int ICDIPR34;
				unsigned int ICDIPR35;
				unsigned int ICDIPR36;
				unsigned int ICDIPR37;
				unsigned int ICDIPR38;
				unsigned int ICDIPR39;
}ipr;
#define ICDIPR  (* (volatile ipr *)0x10490400 )

/* Processor targets register  */
typedef struct {
				unsigned int ICDIPTR0_CPU0;
				unsigned int ICDIPTR1_CPU0;
				unsigned int ICDIPTR2_CPU0;
				unsigned int ICDIPTR3_CPU0;
				unsigned int ICDIPTR4_CPU0;
				unsigned int ICDIPTR5_CPU0;
				unsigned int ICDIPTR6_CPU0;
				unsigned int ICDIPTR7_CPU0;
				unsigned int ICDIPTR8;
				unsigned int ICDIPTR9;
				unsigned int ICDIPTR10;
				unsigned int ICDIPTR11;
				unsigned int ICDIPTR12;
				unsigned int ICDIPTR13;
				unsigned int ICDIPTR14;
				unsigned int ICDIPTR15;
				unsigned int ICDIPTR16;
				unsigned int ICDIPTR17;
				unsigned int ICDIPTR18;
				unsigned int ICDIPTR19;
				unsigned int ICDIPTR20;
				unsigned int ICDIPTR21;
				unsigned int ICDIPTR22;
				unsigned int ICDIPTR23;
				unsigned int ICDIPTR24;
				unsigned int ICDIPTR25;
				unsigned int ICDIPTR26;
				unsigned int ICDIPTR27;
				unsigned int ICDIPTR28;
				unsigned int ICDIPTR29;
				unsigned int ICDIPTR30;
				unsigned int ICDIPTR31;
				unsigned int ICDIPTR32;
				unsigned int ICDIPTR33;
				unsigned int ICDIPTR34;
				unsigned int ICDIPTR35;
				unsigned int ICDIPTR36;
				unsigned int ICDIPTR37;
				unsigned int ICDIPTR38;
				unsigned int ICDIPTR39;
}iptr;
#define ICDIPTR  (* (volatile iptr *)0x10490800 )

/* Interrupt configuration register  */
typedef struct {
				unsigned int ICDICFR0_CPU0;
				unsigned int ICDICFR1_CPU0;
				unsigned int ICDICFR2;
				unsigned int ICDICFR3;
				unsigned int ICDICFR4;
				unsigned int ICDICFR5;
				unsigned int ICDICFR6;
				unsigned int ICDICFR7;
				unsigned int ICDICFR8;
				unsigned int ICDICFR9;
}icfr;
#define ICDICFR  (* (volatile icfr *)0X10490C00 )

#define PPI_STATUS_CPU0		__REG(0X10490D00)

/* SPI status register  */
typedef struct {
				unsigned int STATUS0;	//SPI[31:0] status register
				unsigned int STATUS1;	//SPI[63:32] status register
				unsigned int STATUS2;	//SPI[95:64] status register
				unsigned int STATUS3;	//SPI[127:96] status register
}icdspi_status;
#define ICDSPI_STATUS  (* (volatile icdspi_status *)0X10490D04 )

/*  Software generated interrupt register  */
#define ICDSGIR		__REG(0X10490F00)


/* CPU1 interrupt's register  */
typedef struct {
				unsigned int ICDISR0;
				unsigned int ICDISER0;
				unsigned int ICDICER0;
				unsigned int ICDISPR0;
				unsigned int ICDICPR0;
				unsigned int ICDABR0;
				unsigned int ICDIPR0;
				unsigned int ICDIPR1;
				unsigned int ICDIPR2;
				unsigned int ICDIPR3;
				unsigned int ICDIPR4;
				unsigned int ICDIPR5;
				unsigned int ICDIPR6;
				unsigned int ICDIPR7;
				unsigned int ICDIPTR0;
				unsigned int ICDIPTR1;
				unsigned int ICDIPTR2;
				unsigned int ICDIPTR3;
				unsigned int ICDIPTR4;
				unsigned int ICDIPTR5;
				unsigned int ICDIPTR6;
				unsigned int ICDIPTR7;
				unsigned int ICDICFR0;
				unsigned int ICDICFR1;
				unsigned int PPI_STATUS;
}icdcpu1;
#define ICDCPU1  (* (volatile icdcpu1 *)0X10494080 )

/* CPU2 interrupt's register  */
typedef struct {
				unsigned int ICDISR0;
				unsigned int ICDISER0;
				unsigned int ICDICER0;
				unsigned int ICDISPR0;
				unsigned int ICDICPR0;
				unsigned int ICDABR0;
				unsigned int ICDIPR0;
				unsigned int ICDIPR1;
				unsigned int ICDIPR2;
				unsigned int ICDIPR3;
				unsigned int ICDIPR4;
				unsigned int ICDIPR5;
				unsigned int ICDIPR6;
				unsigned int ICDIPR7;
				unsigned int ICDIPTR0;
				unsigned int ICDIPTR1;
				unsigned int ICDIPTR2;
				unsigned int ICDIPTR3;
				unsigned int ICDIPTR4;
				unsigned int ICDIPTR5;
				unsigned int ICDIPTR6;
				unsigned int ICDIPTR7;
				unsigned int ICDICFR0;
				unsigned int ICDICFR1;
				unsigned int PPI_STATUS;
}icdcpu2;
#define ICDCPU2  (* (volatile icdcpu2 *)0X10498080 )

/* CPU3 interrupt's register  */
typedef struct {
				unsigned int ICDISR0;
				unsigned int ICDISER0;
				unsigned int ICDICER0;
				unsigned int ICDISPR0;
				unsigned int ICDICPR0;
				unsigned int ICDABR0;
				unsigned int ICDIPR0;
				unsigned int ICDIPR1;
				unsigned int ICDIPR2;
				unsigned int ICDIPR3;
				unsigned int ICDIPR4;
				unsigned int ICDIPR5;
				unsigned int ICDIPR6;
				unsigned int ICDIPR7;
				unsigned int ICDIPTR0;
				unsigned int ICDIPTR1;
				unsigned int ICDIPTR2;
				unsigned int ICDIPTR3;
				unsigned int ICDIPTR4;
				unsigned int ICDIPTR5;
				unsigned int ICDIPTR6;
				unsigned int ICDIPTR7;
				unsigned int ICDICFR0;
				unsigned int ICDICFR1;
				unsigned int PPI_STATUS;
}icdcpu3;
#define ICDCPU3  (* (volatile icdcpu3 *)0X1049C080 )

#endif
