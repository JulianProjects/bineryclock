// Copyright [Year] [Your Name]
// Distributed under the BSD 3-Clause License.
// See LICENSE file for details.
//
// Timer module for AVR microcontroller.
// Provides timing functionality and maintains current time state.

#ifndef ROLEX_ICE_INCLUDE_TIMER_H_
#define ROLEX_ICE_INCLUDE_TIMER_H_

#include <stdbool.h>
#include <stdint.h>

// Flag set when a new second has elapsed.
extern volatile bool neue_sekunde_flag;

// Current seconds (0-59).
extern volatile uint8_t Sekunde;

// Current minutes (0-59).
extern volatile uint8_t Minute;

// Current hours (0-23).
extern volatile uint8_t Stunde;

// Flag indicating sleep mode is active.
extern volatile uint8_t sleep_mode_active;

// Initializes timer and interrupts.
void InitTimer(void);

// Updates current time based on timer state.
void CurrentTime(void);

#endif  // ROLEX_ICE_INCLUDE_TIMER_H_