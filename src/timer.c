// Copyright [Year] [Your Name]
// Distributed under the BSD 3-Clause License.
// See LICENSE file for details.
//
// Timer module implementation for AVR microcontroller.
// Manages TIMER2 for accurate timekeeping with external crystal oscillator.

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdint.h>

#include "timer.h"

void InitTimer(void) {
  // Enable asynchronous mode with external 32.768kHz crystal.
  ASSR |= (1 << AS2);

  // Reset timer counter.
  TCNT2 = 0;

  // Set prescaler to 128 (CS22, CS20).
  TCCR2B = (1 << CS22) | (1 << CS20);

  // Wait for all timer updates to complete.
  while (ASSR & ((1 << TCN2UB) | (1 << TCR2AUB) | (1 << TCR2BUB))) {
    // Busy wait
  }

  // Enable timer overflow interrupt.
  TIMSK2 = (1 << TOIE2);
}

// Timer 2 overflow interrupt handler.
// Called approximately once per second with 32.768kHz crystal.
ISR(TIMER2_OVF_vect) {
  neue_sekunde_flag = 1;
}

void CurrentTime(void) {
  if (!sleep_mode_active) {
    neue_sekunde_flag = 1;
  }
  neue_sekunde_flag = 0;
  
  // Increment seconds.
  Sekunde++;
  if (Sekunde >= 60) {
    Sekunde = 0;
    Minute++;
  }
  
  // Increment minutes.
  if (Minute >= 60) {
    Minute = 0;
    Stunde++;
  }
  
  // Increment hours (24-hour format).
  if (Stunde >= 24) {
    Stunde = 0;
  }
}