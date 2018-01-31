#ifndef EXYNOS4412_H
#define EXYNOS4412_H

// Exynos-4412 Controller
struct exynos4412_wdt {
	unsigned int WTCON;
	unsigned int WTDAT;
	unsigned int WTCNT;
	unsigned int WTCLRINT;
};
#define WDT_ADDR ((volatile struct exynos4412_wdt *)0x10060000)
#define WDT (*WDT_ADDR)

struct exynos4412_gpx1 {
	unsigned int CON;
	unsigned int DAT;
	unsigned int PUD;
	unsigned int DRV;
};

#define GPX1_ADDR ((volatile struct exynos4412_gpx1 *)0x11000C20)
#define GPX1 (*GPX1_ADDR)

struct exynos4412_gpx2 {
	unsigned int CON;
	unsigned int DAT;
	unsigned int PUD;
	unsigned int DRV;
};

#define GPX2_ADDR ((volatile struct exynos4412_gpx2 *)0x11000C40)
#define GPX2 (*GPX2_ADDR)

struct exynos4412_gpf3 {
	unsigned int CON;
	unsigned int DAT;
	unsigned int PUD;
	unsigned int DRV;
};

#define GPF3_ADDR ((volatile struct exynos4412_gpf3 *)0x114001E0)
#define GPF3 (*GPF3_ADDR)


#include "irq.h"

#endif
