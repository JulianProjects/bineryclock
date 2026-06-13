// Copyright [Year] [Your Name]
// Distributed under the BSD 3-Clause License.
// See LICENSE file for details.
//
// Button handling module for AVR microcontroller.
// Provides functions to detect button presses with debouncing.

#ifndef ROLEX_ICE_INCLUDE_BUTTON_H_
#define ROLEX_ICE_INCLUDE_BUTTON_H_

#include <stdbool.h>
#include <stdint.h>

// Debouncing counters for button press detection.
extern int entpreller_first_press;
extern int entpreller_second_press;

// Flag for button 4 getter state.
extern bool button_4_getter;

// Initializes button inputs and interrupts.
void InitButton(void);

// Checks if button 4 is currently pressed.
bool Button4Pressed(void);

// Checks if button 3 is currently pressed.
bool Button3Pressed(void);

// Checks if button 2 is currently pressed.
bool Button2Pressed(void);

// Performs debouncing check for button presses (~20ms at 1MHz, Prescaler 128).
bool Entprellt(void);

// Returns the ID of the pressed button (1, 2, 3, or 4), or 1 if none pressed.
int ButtonPressed(void);

#endif  // ROLEX_ICE_INCLUDE_BUTTON_H_