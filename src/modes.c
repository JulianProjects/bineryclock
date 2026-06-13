// Copyright [Year] [Your Name]
// Distributed under the BSD 3-Clause License.
// See LICENSE file for details.
//
// Mode handling implementation for Rolex Ice watch.
// Implements different operation modes and user interactions.

#include <avr/io.h>
#include <stdbool.h>
#include <stdint.h>

#include "button.h"
#include "led.h"
#include "modes.h"
#include "pwm.h"
#include "sleep_mode.h"

// Current operation mode.
volatile extern int modus;

// Current brightness level (0-100).
extern int brightness;

// Sleep mode state.
extern volatile uint8_t sleep_mode_active;

volatile void HandleMode(void) {
  // Mode dispatcher - added placeholder
  // TODO: Implement main mode dispatch logic.
}

void HandleMode1(void) {
  // Display minutes and hours.
  DisplayMinutesAndHours();
  modus = ButtonPressed();
}

void HandleMode2(void) {
  // Display seconds.
  DisplaySeconds();
  modus = ButtonPressed();

  if (modus == 1) {
    modus = 2;
  } else if (modus == 2) {
    modus = 1;
  }
}

void HandleMode4(void) {
  // Brightness adjustment mode.
  SetAllLedsOn();
  modus = ButtonPressed();

  if (modus == 1) {
    modus = 4;
  } else if (modus == 4) {
    // Decrease brightness on button press.
    if (button_4_getter) {
      brightness -= 25;
      SetPwmPb1(brightness);
    }

    // Reset brightness when at minimum.
    if (brightness <= 0) {
      brightness = 100;
      modus = 1;
    }
  }
}
    }
}

void handle_mode_3(void)
{
    manage_sleep_mode();
}

void handle_mode(void)
{
    switch(modus)
    {
        case 1:
            handle_mode_1();
            break;

        case 2:
            handle_mode_2();
            break;

        case 3:

            handle_mode_3();
            break;

        case 4:

            handle_mode_4();
            break;

        default: break;
    }
}