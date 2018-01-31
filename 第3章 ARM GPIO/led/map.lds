OUTPUT_FORMAT("elf32-littlearm", "elf32-littlearm", "elf32-littlearm")
OUTPUT_ARCH(arm)
ENTRY(_start)
SECTIONS
{
	. = 0x40000000;
	. = ALIGN(4);
	.text :
	{
		start.o(.text)
		*(.text)
	}
    . = ALIGN(4);
    .data : 
	{
		*(.data)
	}
    . = ALIGN(4);
    .bss :
    {
		*(.bss)
	}
}
