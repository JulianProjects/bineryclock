// UART serial communication implementation for binary clock.
// Provides serial input/output at 4800 baud for debugging and communication.

#include <avr/io.h>
#include <stdint.h>

static const int kUartBaud = 4800;

void UartInit(uint16_t ubrr) {
  // Set baud rate registers.
  UBRR0H = (uint8_t)(ubrr >> 8);
  UBRR0L = (uint8_t)ubrr;

  // Enable transmit and receive.
  UCSR0B = (1 << RXEN0) | (1 << TXEN0);
  
  // Set frame format: 8 data bits, 1 stop bit, no parity.
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void UartPutchar(char c) {
  // Wait for transmit buffer to be empty.
  while (!(UCSR0A & (1 << UDRE0))) {
    // Busy wait
  }
  
  // Send character.
  UDR0 = c;
}

void UartPuts(char* s) {
  // Send each character in string until null terminator.
  while (*s) {
    UartPutchar(*s++);
  }
}

char UartGetchar(void) {
  // Wait for data to be received.
  while (!(UCSR0A & (1 << RXC0))) {
    // Busy wait
  }
  
  // Return received character.
  return UDR0;
}