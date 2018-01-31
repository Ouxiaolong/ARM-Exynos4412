

#ifndef __EXYNOS_4412_H_
#define _EXYNOS_4412_H_

// Exynos-4412 Controller

struct exynos4412_gpx1 {
	unsigned int CON;
	unsigned int DAT;
	unsigned int PUD;
	unsigned int DRV;
};

#define GPX1_ADDR ((volatile struct exynos4412_gpx1 *)0x11000C20)
#define GPX1 (*GPX1_ADDR)

//方式一
struct exynos4412_gpx2 {
	unsigned int CON;
	unsigned int DAT;
	unsigned int PUD;
	unsigned int DRV;
};

#define GPX2_ADDR ((volatile struct exynos4412_gpx2 *)0x11000C40)
#define GPX2 (*GPX2_ADDR)

//方式二
typedef struct {  
    unsigned int CON;  
    unsigned int DAT;  
    unsigned int PUD;  
    unsigned int DRV;  
}gpx2;  
#define GPX2 (* (volatile gpx2 *)0x11000C40 )  

struct exynos4412_gpf3 {
	unsigned int CON;
	unsigned int DAT;
	unsigned int PUD;
	unsigned int DRV;
};

#define GPF3_ADDR ((volatile struct exynos4412_gpf3 *)0x114001E0)
#define GPF3 (*GPF3_ADDR)


#endif
