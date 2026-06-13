#ifndef LED_H_
#define LED_H_

#include <stdint.h>

void init_led(void);
void set_all_leds_off(void);
void set_all_leds_on(void);

void display_minutes(uint8_t minutes);
void display_hours(void);
void display_minutes_and_hours(void);
void display_seconds(void);

#endif