#ifndef IRQ_H
#define IRQ_H

void irq_init(void);
int do_irq(void);

int gic_cpu0_set_pending(int irq_num);

#endif
