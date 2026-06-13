#define BAUD 4800
#define MYUBRR (F_CPU/16/BAUD-1)
#include <avr/io.h>

void uart_init(uint16_t ubrr)
{
    UBRR0H = (uint8_t)(ubrr >> 8);
    UBRR0L = (uint8_t)ubrr;

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void uart_putchar(char c)
{
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

void uart_puts(char *s)
{
    while (*s) {
        uart_putchar(*s++);
    }
}

char uart_getchar(void)
{
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}