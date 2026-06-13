// Board test module implementation for binary clock.
// Tests all LED outputs by sequentially lighting each LED for 500ms.

#include <avr/io.h>
#include <util/delay.h>

static const int kLedOnDelayMs = 500;

void TestBoard(void) {
  // Turn all LEDs off initially.
  // Since PB1 is HIGH (common line), LEDs turn on when cathode pins are LOW.
  PORTB |= (1 << PB0) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5);
  PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2);
  PORTD |= (1 << PD5) | (1 << PD6) | (1 << PD7);

  // Test LED on PB2 (D1).
  PORTB &= ~(1 << PB2);
  _delay_ms(kLedOnDelayMs);
  PORTB |= (1 << PB2);

  // Test LED on PB3 (D2).
  PORTB &= ~(1 << PB3);
  _delay_ms(kLedOnDelayMs);
  PORTB |= (1 << PB3);

  // Test LED on PB4 (D3).
  PORTB &= ~(1 << PB4);
  _delay_ms(kLedOnDelayMs);
  PORTB |= (1 << PB4);

  // Test LED on PB5 (D4).
  PORTB &= ~(1 << PB5);
  _delay_ms(kLedOnDelayMs);
  PORTB |= (1 << PB5);

  // Test LED on PC0 (D5).
  PORTC &= ~(1 << PC0);
  _delay_ms(kLedOnDelayMs);
  PORTC |= (1 << PC0);

  // Test LED on PC1 (D6).
  PORTC &= ~(1 << PC1);
  _delay_ms(kLedOnDelayMs);
  PORTC |= (1 << PC1);

  // Test LED on PC2 (D7).
  PORTC &= ~(1 << PC2);
  _delay_ms(kLedOnDelayMs);
  PORTC |= (1 << PC2);

  // Test LED on PB0 (D8).
  PORTB &= ~(1 << PB0);
  _delay_ms(kLedOnDelayMs);
  PORTB |= (1 << PB0);

  // Test LED on PD7 (D9).
  PORTD &= ~(1 << PD7);
  _delay_ms(kLedOnDelayMs);
  PORTD |= (1 << PD7);

  // Test LED on PD6 (D10).
  PORTD &= ~(1 << PD6);
  _delay_ms(kLedOnDelayMs);
  PORTD |= (1 << PD6);

  // Test LED on PD5 (D11).
  PORTD &= ~(1 << PD5);
  _delay_ms(kLedOnDelayMs);
  PORTD |= (1 << PD5);
}