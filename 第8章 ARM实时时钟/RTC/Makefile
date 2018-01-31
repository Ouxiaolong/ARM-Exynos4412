# CORTEX-A9 PERI DRIVER CODE
# VERSION 2.0
# ATHUOR liujh@farsight.com.cn
# MODIFY DATE 
# 2014.05.28  Makefile

CROSS_COMPILE = arm-none-eabi-
NAME = rtc
#=============================================================================#
CFLAGS += -g   -O0  -mabi=apcs-gnu -mfpu=neon -mfloat-abi=softfp  -fno-builtin \
			-nostdinc  -I ./common/include      		                                       
LD	= $(CROSS_COMPILE)ld
CC	= $(CROSS_COMPILE)gcc
OBJCOPY = $(CROSS_COMPILE)objcopy
OBJDUMP = $(CROSS_COMPILE)objdump
#============================================================================#
OBJSss 	:= $(wildcard start/*.S) $(wildcard start/*.c) $(wildcard common/src/*.c) \
		   $(wildcard common/src/*.S) $(wildcard usr/*.c) $(wildcard *.c) $(wildcard *.S)
OBJSs  	:= $(patsubst %.S,%.o,$(OBJSss))
OBJS 	:= $(patsubst %.c,%.o,$(OBJSs))
#============================================================================#
%.o: %.S 
	$(CC) $(CFLAGS) -c -o  $@ $<
%.o: %.c
	$(CC) $(CFLAGS) -c -o  $@ $<
all:clean  $(OBJS)
	$(LD)  $(OBJS) -T map.lds -o $(NAME).elf
	$(OBJCOPY)  -O binary  $(NAME).elf $(NAME).bin 
	$(OBJDUMP) -D $(NAME).elf > $(NAME).dis 
#============================================================================#
clean:
	rm -rf $(OBJS) *.elf *.bin *.dis *.o
#============================================================================#