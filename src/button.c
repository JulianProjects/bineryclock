// Copyright [Year] [Your Name]
// Distributed under the BSD 3-Clause License.
// See LICENSE file for details.
//
// Button handling implementation for AVR microcontroller.
// Implements debounced button input detection for Rolex Ice watch.

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

#include "button.h"

// Debouncing threshold in timer units (~20ms at 1MHz, Prescaler 128).
static const int kDebounceThreshold = 64;

// Extern variable declarations for debouncing state.
int entpreller_first_press = 0;
int entpreller_second_press = 0;
bool button_4_getter = false;

// Extern variable from timer module.
extern volatile uint8_t Sekunde;

void InitButton(void) {
  // Configure PD3 as input with pull-up.
  DDRD &= ~(1 << PD3);
  PORTD |= (1 << PD3);
  
  // Configure external interrupt INT1 on PD3.
  EICRA = 0;
  EIMSK |= (1 << INT1);
}

bool Button4Pressed(void) {
  // Configure PD4 as input with pull-up.
  DDRD &= ~(1 << PD4);
  PORTD |= (1 << PD4);
  
  // Return true if button is pressed (pin is LOW).
  return !(PIND & (1 << PD4));
}

bool Button3Pressed(void) {
  // Configure PD3 as input with pull-up.
  DDRD &= ~(1 << PD3);
  PORTD |= (1 << PD3);
  
  // Return true if button is pressed (pin is LOW).
  return !(PIND & (1 << PD3));
}

bool Button2Pressed(void) {
  // Configure PD2 as input with pull-up.
  DDRD &= ~(1 << PD2);
  PORTD |= (1 << PD2);
  
  // Return true if button is pressed (pin is LOW).
  return !(PIND & (1 << PD2));
}

bool Entprellt(void) {
  static uint16_t alt = 0;
  uint16_t neu = ((uint16_t)Sekunde << 8) | TCNT2;

  // Check if enough time has passed since last press.
  if ((uint16_t)(neu - alt) < kDebounceThreshold) {
    return false;
  }

  alt = neu;
  return true;
}

int ButtonPressed(void) {
  if (Button4Pressed()) {
    if (Entprellt()) {
      button_4_getter = true;
      return 4;
    } else {
      button_4_getter = false;
    }
  } else if (Button2Pressed()) {
    if (Entprellt()) {
      return 2;
    }
  }
  return 1;
}