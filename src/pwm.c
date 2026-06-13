// PWM implementation for brightness control on binary clock.
// Controls LED brightness using Timer 1 in PWM mode on pin PB1 (OC1A).

#include <avr/io.h>

void SetPwmPb1(int pwm_value) {
  // Configure Timer 1 for Fast PWM mode (8-bit).
  // WGM10=1, WGM12=1 => Fast PWM, 8-bit mode.
  TCCR1A = (1 << WGM10) | (1 << COM1A1);  // OC1A (PB1) in non-inverted mode.

  // Set prescaler to 8 (CS11).
  TCCR1B = (1 << WGM12) | (1 << CS11);

  // Set duty cycle (0-255).
  OCR1A = pwm_value;
}