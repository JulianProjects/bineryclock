// LED display module for AVR microcontroller.
// Controls LED output for time display on pins B, C, and D.

#ifndef BINARYCLOCK_INCLUDE_LED_H_
#define BINARYCLOCK_INCLUDE_LED_H_

#include <stdint.h>

// Initializes LED pins as outputs.
// Sets up ports B, C, and D for LED control.
void InitLed(void);

// Turns off all LEDs by setting pins to HIGH (active low).
void SetAllLedsOff(void);

// Turns on all LEDs by setting pins to LOW (active low).
void SetAllLedsOn(void);

// Displays minutes in binary on 6 LED pins.
// Encodes minutes 0-59 across pins B2-B5 and C0-C1.
void DisplayMinutes(uint8_t minutes);

// Displays current hours on LED pins.
void DisplayHours(void);

// Displays both minutes and hours on LED pins.
void DisplayMinutesAndHours(void);

// Displays seconds on LED pins.
void DisplaySeconds(void);

#endif  // BINARYCLOCK_INCLUDE_LED_H_