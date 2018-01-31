#ifndef ___EXYNOS4412_CLOCK_
#define ___EXYNOS4412_CLOCK_


#define	CLOCK_BASE				0x10030000
#define CMU_BASE                0x10030000

#define CLK_SRC_CPU_OFFSET      0x14200
#define CLK_MUX_STAT_CPU_OFFSET 0x14400
#define CLK_DIV_DMC0_OFFSET     0x10500
#define CLK_DIV_DMC1_OFFSET     0x10504

#define CLK_SRC_TOP0_OFFSET     0x0C210
#define CLK_SRC_TOP1_OFFSET     0x0C214
#define CLK_MUX_STAT_TOP_OFFSET     0x0C410
#define CLK_MUX_STAT_TOP1_OFFSET    0x0C414

#define CLK_DIV_TOP_OFFSET      0x0C510

#define CLK_SRC_LEFTBUS_OFFSET      0x04200
#define CLK_MUX_STAT_LEFTBUS_OFFSET 0x04400
#define CLK_DIV_LEFTBUS_OFFSET      0x04500

#define CLK_SRC_RIGHTBUS_OFFSET     0x08200
#define CLK_MUX_STAT_RIGHTBUS_OFFSET    0x08400
#define CLK_DIV_RIGHTBUS_OFFSET     0x08500

#define APLL_LOCK_OFFSET        0x14000
#define MPLL_LOCK_OFFSET        0x10008
#define EPLL_LOCK_OFFSET        0x0C010
#define VPLL_LOCK_OFFSET        0x0C020

#define CLK_DIV_CPU0_OFFSET     0x14500
#define CLK_DIV_CPU1_OFFSET     0x14504

#define APLL_CON0_OFFSET        0x14100
#define APLL_CON1_OFFSET        0x14104

#define MPLL_CON0_OFFSET        0x10108
#define MPLL_CON1_OFFSET        0x1010C

#define CLK_SRC_PERIL0_OFFSET       0x0C250
#define CLK_DIV_PERIL0_OFFSET       0x0C550

/*
 * UART
 */
#define ELFIN_UART0_OFFSET      0x00000
#define ELFIN_UART1_OFFSET      0x10000
#define ELFIN_UART2_OFFSET      0x20000
#define ELFIN_UART3_OFFSET      0x30000

#define ELFIN_UART_BASE         0x13800000
#define ELFIN_UART_CONSOLE_BASE (ELFIN_UART_BASE + ELFIN_UART2_OFFSET)

#define ULCON_OFFSET            0x00
#define UCON_OFFSET         	0x04
#define UFCON_OFFSET            0x08
#define UMCON_OFFSET            0x0C
#define UTRSTAT_OFFSET          0x10
#define UERSTAT_OFFSET          0x14
#define UFSTAT_OFFSET           0x18
#define UMSTAT_OFFSET           0x1C
#define UTXH_OFFSET         	0x20
#define URXH_OFFSET         	0x24
#define UBRDIV_OFFSET           0x28
#define UFRACVAL_OFFSET         0x2C
#define UINTP_OFFSET            0x30
#define UINTSP_OFFSET           0x34
#define UINTM_OFFSET            0x38


 /* Set PLL  */
#define APLL_MDIV   0x7D
#define APLL_PDIV   0x3
#define APLL_SDIV   0x0

#define MPLL_MDIV   0x64
#define MPLL_PDIV   0x3
#define MPLL_SDIV   0x0

#define EPLL_MDIV   0x40
#define EPLL_PDIV   0x2
#define EPLL_SDIV   0x3

#define VPLL_MDIV   0x48
#define VPLL_PDIV   0x2
#define VPLL_SDIV   0x3

#define set_pll(mdiv, pdiv, sdiv)   (1<<31 | mdiv<<16 | pdiv<<8 | sdiv)

#define APLL_CON0_VAL   set_pll(APLL_MDIV,APLL_PDIV,APLL_SDIV)
/*
 * Fout = M*Fin/(P*2^S) = 125 * 24 / ( 3 * 2^0 ) = 1000 MHz = 1Ghz
 * */

#define MPLL_CON0_VAL   set_pll(MPLL_MDIV,MPLL_PDIV,MPLL_SDIV)
/*
 * Fout = M*Fin/(P*2^S) = 100 * 24 / ( 3 * 2^0 ) = 800Mhz
 * */
#define EPLL_CON0_VAL   set_pll(EPLL_MDIV,EPLL_PDIV,EPLL_SDIV)
#define VPLL_CON0_VAL   set_pll(VPLL_MDIV,VPLL_PDIV,VPLL_SDIV)

/**************** VALUE *************/

/* CLK_DIV_DMC0 */
#define DMCP_RATIO      0x1
#define DMCD_RATIO      0x1
#define DMC_RATIO       0x1
#define DPHY_RATIO      0x1
#define ACP_PCLK_RATIO      0x1
#define ACP_RATIO       0x3

#define CLK_DIV_DMC0_VAL  ((DMCP_RATIO << 20)    \
		                | (DMCD_RATIO << 16)    \
		                | (DMC_RATIO << 12) \
		                | (DPHY_RATIO << 8) \
		                | (ACP_PCLK_RATIO << 4) \
		                | (ACP_RATIO))

/* CLK_DIV_DMC1 */
#define DPM_RATIO           0x1
#define DVSEM_RATIO         0x1
#define PWI_RATIO           0x1
#define CLK_DIV_DMC1_VAL    ((DPM_RATIO << 24) \
						  | (DVSEM_RATIO << 16) \
						  | (PWI_RATIO << 8))


/* CLK_DIV_TOP  */
#define ONENAND_RATIO   0x0
#define ACLK_133_RATIO  0x5
#define ACLK_160_RATIO  0x4
#define ACLK_100_RATIO  0x7
#define ACLK_200_RATIO  0x3
#define CLK_DIV_TOP_VAL ((ONENAND_RATIO << 16) \
             | (ACLK_133_RATIO << 12)    \
             | (ACLK_160_RATIO << 8) \
             | (ACLK_100_RATIO << 4) \
             | (ACLK_200_RATIO))


/* CLK_DIV_LEFRBUS  */
#define GPL_RATIO           0x1
#define GDL_RATIO           0x3
#define CLK_DIV_LEFRBUS_VAL ((GPL_RATIO << 4) \
                 | (GDL_RATIO))


/* CLK_DIV_RIGHTBUS */
#define GPR_RATIO           0x1
#define GDR_RATIO           0x3
#define CLK_DIV_RIGHTBUS_VAL    ((GPR_RATIO << 4) \
                 | (GDR_RATIO))


/* APLL_LOCK        */
#define APLL_LOCK_VAL   0x000002F1
/* MPLL_LOCK    */
#define MPLL_LOCK_VAL   0x000002F1
/* EPLL_LOCK        */
#define EPLL_LOCK_VAL   0x00002321
/* VPLL_LOCK        */
#define VPLL_LOCK_VAL   0x00002321


 /* CLK_DIV_CPU0 */
 #define CORE2_RATIO         0x0
 #define APLL_RATIO          0x1
 #define PCLK_DBG_RATIO      0x1
 #define ATB_RATIO           0x4
 #define PERIPH_RATIO        0x3
 #define COREM1_RATIO        0x7
 #define COREM0_RATIO        0x3
 #define CORE_RATIO          0x0
 #define CLK_DIV_CPU0_VAL        ((CORE2_RATIO << 28)    \
                                  | (APLL_RATIO << 24)     \
                                  | (PCLK_DBG_RATIO << 20)\
                                 | (ATB_RATIO << 16)     \
                                 | (PERIPH_RATIO <<12)   \
                                 | (COREM1_RATIO << 8)   \
                                 | (COREM0_RATIO << 4)   \
                                 | (CORE_RATIO))

/* CLK_DIV_CPU1 */
#define HPM_RATIO           0x0
#define COPY_RATIO          0x4
#define CLK_DIV_CPU1_VAL    ((HPM_RATIO << 4) | (COPY_RATIO))

/* APLL_CON1    */
#define APLL_CON1_VAL   0x00803800
 /* MPLL_CON1    */
 #define MPLL_CON1_VAL   0x00803800

/* CLK_SRC_PERIL0   */
#define PWM_SEL     0
#define UART5_SEL   6
#define UART4_SEL   6
#define UART3_SEL   6
#define UART2_SEL   6
#define UART1_SEL   6
#define UART0_SEL   6
#define CLK_SRC_PERIL0_VAL  ((PWM_SEL << 24)\
                 | (UART5_SEL << 20)  \
                 | (UART4_SEL << 16) \
                 | (UART3_SEL << 12) \
                 | (UART2_SEL<< 8)   \
                 | (UART1_SEL << 4)  \
                 | (UART0_SEL))

/* CLK_DIV_PERIL0   */
#define UART5_RATIO 7
#define UART4_RATIO 7
#define UART3_RATIO 7
#define UART2_RATIO 7
#define UART1_RATIO 7
#define UART0_RATIO 7
#define CLK_DIV_PERIL0_VAL  ((UART5_RATIO << 20) \
                 | (UART4_RATIO << 16) \
                 | (UART3_RATIO << 12)   \
                 | (UART2_RATIO << 8)    \
                 | (UART1_RATIO << 4)    \
                 | (UART0_RATIO))


#define UART_UBRDIV_VAL                 0x35     /* (SCLK_UART/(115200*16) -1) */
#define UART_UDIVSLOT_VAL               0x5 	/*((((SCLK_UART*10/(115200*16) -10))%10)*16/10)*/

#endif
