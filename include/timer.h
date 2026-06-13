#ifndef TIMER_H
#define TIMER_H
#include <stdint.h>
#include <stdbool.h>

extern volatile bool neue_sekunde_flag;
extern volatile uint8_t Sekunde;
extern volatile uint8_t Minute;
extern volatile uint8_t Stunde;
extern volatile uint8_t sleep_mode_active;

void initTimer(void);
void current_time(void);

#endif