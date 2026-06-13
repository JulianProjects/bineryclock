// Copyright [Year] [Your Name]
// Distributed under the BSD 3-Clause License.
// See LICENSE file for details.
//
// UART serial communication module for AVR microcontroller.
// Provides serial input/output functions for debugging and communication.

#ifndef ROLEX_ICE_INCLUDE_UART_H_
#define ROLEX_ICE_INCLUDE_UART_H_

#include <stdint.h>

// Baud rate for UART communication.
static const int kUartBaud = 4800;

// UBRR register value calculated from F_CPU and baud rate.
// Formula: UBRR = (F_CPU / 16 / BAUD) - 1
#define UART_UBRR (F_CPU / 16 / kUartBaud - 1)

// Initializes UART with specified UBRR value.
// Parameters:
//   ubrr: UBRR register value for desired baud rate.
void UartInit(uint16_t ubrr);

// Transmits a single character via UART.
// Parameters:
//   c: Character to transmit.
void UartPutchar(char c);

// Transmits a null-terminated string via UART.
// Parameters:
//   s: Pointer to string to transmit.
void UartPuts(char* s);

// Receives a single character from UART.
// Returns: Received character.
char UartGetchar(void);

#endif  // ROLEX_ICE_INCLUDE_UART_H_