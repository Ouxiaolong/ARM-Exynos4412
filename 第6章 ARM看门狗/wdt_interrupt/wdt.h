#ifndef WDT_H
#define WDT_H

int wdt_init_interrupt(int pre, int sel);
int wdt_start_interrupt(int timeout);

int wdt_handler();
int wdt_clear_pending();

#endif