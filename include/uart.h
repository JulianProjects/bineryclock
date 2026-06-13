#ifndef UART_H
#define UART_H

#include <stdint.h>

#define BAUD 4800
#define MYUBRR (F_CPU / 16 / BAUD - 1)

void uart_init(uint16_t ubrr);
void uart_putchar(char c);
void uart_puts(char *s);
char uart_getchar(void);

#endif