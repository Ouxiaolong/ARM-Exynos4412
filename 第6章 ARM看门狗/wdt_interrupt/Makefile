TARGET	:= my_a9
all: $(TARGET)

CROSS_COMPILE ?= /opt/gcc-4.6.4/bin/arm-none-linux-gnueabi-
# CROSS_COMPILE ?= arm-none-linux-gnueabi-
CC		:= $(CROSS_COMPILE)gcc

CFLAGS	+= -march=armv7-a -mtune=cortex-a9
CFLAGS	+= -nostdinc -nostdlib
CFLAGS	+= -fno-builtin -fno-builtin-function

ASFLAGS	+= -march=armv7-a -mtune=cortex-a9
ASFLAGS	+= -nostdinc -nostdlib
LDFALGS	+= -march=armv7-a -mtune=cortex-a9 -lgcc

OBJS	:= $(patsubst %.c, %.o, $(wildcard *.c))
OBJS	+= $(patsubst %.S, %.o, $(wildcard *.S))

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ -Tmap.lds -nostdlib $(LDFALGS)
	$(CROSS_COMPILE)objdump -d $@ > $@.s
	$(CROSS_COMPILE)objcopy -O binary $@ $@.bin

%.o: %.S
	$(CC) -c $^ $(ASFLAGS)

%.o: %.c
	$(CC) -c $^ $(CFLAGS)


install: $(TARGET)
	cp $(TARGET).bin /tftpboot

clean:
	rm -f $(TARGET)
	rm -f $(OBJS)
	rm -f $(TARGET).s
	rm -f $(TARGET).bin
