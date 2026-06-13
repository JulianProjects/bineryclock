// Copyright [Year] [Your Name]
// Distributed under the BSD 3-Clause License.
// See LICENSE file for details.
//
// Main entry point for Rolex Ice watch firmware.
// Initializes hardware modules and manages main event loop.

#include <avr/interrupt.h>
#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>
#include <util/delay.h>

#include "button.h"
#include "led.h"
#include "modes.h"
#include "pwm.h"
#include "sleep_mode.h"
#include "test_platine.h"
#include "timer.h"
#include "uart.h"

// Global flag for new second event.
volatile bool neue_sekunde_flag = false;

// Current time state variables.
volatile uint8_t Sekunde = 0;   // Current seconds (0-59).
volatile uint8_t Minute = 12;   // Current minutes (0-59).
volatile uint8_t Stunde = 13;   // Current hours (0-23).

// Sleep mode state.
volatile uint8_t sleep_mode_active = 0;

// Button debouncing state.
int entpreller_first_press = 0;
int entpreller_second_press = 0;

// Display brightness level (0-100).
int brightness = 100;

// Button 4 state flag.
bool button_4_getter = false;

// Current operation mode.
volatile int modus = 1;

int main(void) {
  // Initialize hardware modules.
  InitLed();
  InitTimer();
  InitButton();
  InitSleepMode();
  
  // Enable global interrupts.
  sei();

  // Turn off all LEDs initially.
  SetAllLedsOff();
  
  // Main event loop.
  while (1) {
    HandleMode();
  }
  
  return 0;
}