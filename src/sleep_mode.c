// Sleep mode implementation for binary clock.
// Manages low-power sleep modes triggered by pin change interrupt on PD1.

#include <avr/interrupt.h>
#include <avr/io.h>
#include <avr/sleep.h>
#include <stdint.h>

#include "led.h"
#include "sleep_mode.h"

// Sleep mode active flag.
extern volatile uint8_t sleep_mode_active;

// Stores previous state of PD1 (sleep button pin) for edge detection.
static volatile uint8_t kPd1LastState = 1;

static const int kPd1BitPosition = PD1;
static const int kPd1InterruptBit = PCINT17;

void InitSleepMode(void) {
  // Configure PD1 as input with pull-up.
  DDRD &= ~(1 << kPd1BitPosition);
  PORTD |= (1 << kPd1BitPosition);

  // Read initial state of PD1.
  kPd1LastState = (PIND & (1 << kPd1BitPosition)) ? 1 : 0;

  // Enable pin change interrupt group 2 (Port D).
  PCICR |= (1 << PCIE2);
  
  // Enable interrupt for PD1 (PCINT17).
  PCMSK2 |= (1 << kPd1InterruptBit);
  
  // Clear pending interrupt.
  PCIFR |= (1 << PCIF2);

  // Select power-save sleep mode (saves more power than idle mode).
  set_sleep_mode(SLEEP_MODE_PWR_SAVE);
}

// Pin change interrupt handler for Port D.
ISR(PCINT2_vect) {
  uint8_t current_state = (PIND & (1 << kPd1BitPosition)) ? 1 : 0;

  // Toggle sleep mode on falling edge (button press).
  if (kPd1LastState && !current_state) {
    sleep_mode_active = !sleep_mode_active;
  }

  kPd1LastState = current_state;
}

void ManageSleepMode(void) {
  while (sleep_mode_active) {
    // Turn off all LEDs in sleep mode.
    SetAllLedsOff();

    // Wait until button is released (pin goes HIGH).
    while (!(PIND & (1 << kPd1BitPosition))) {
      // Busy wait
    }

    // Enable sleep mode.
    sleep_enable();
    
    // Put CPU to sleep.
    sleep_cpu();
    
    // Disable sleep mode after waking up.
    sleep_disable();
  }
}