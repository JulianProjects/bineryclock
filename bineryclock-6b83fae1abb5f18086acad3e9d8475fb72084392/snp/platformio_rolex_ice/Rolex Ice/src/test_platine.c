#include <avr/io.h>
#include <util/delay.h>

void test_platine(void){
        // Turn all LED lines OFF
        // Since PB1 is HIGH, the LEDs turn on when the other pin is LOW
        // So here all cathode/control lines are set to HIGH = LEDs off
        PORTB |= (1 << PB0) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5);
        PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2);
        PORTD |= (1 << PD5) | (1 << PD6) | (1 << PD7);

            // Turn on D1 for 500 ms, then turn it off again
            PORTB &= ~(1 << PB2);
            _delay_ms(500);
            PORTB |= (1 << PB2);     // D1 off again

            // Turn on D2 for 500 ms, then turn it off again
            PORTB &= ~(1 << PB3);
            _delay_ms(500);
            PORTB |= (1 << PB3);     // D2 off again

            // Turn on D3 for 500 ms, then turn it off again
            PORTB &= ~(1 << PB4);
            _delay_ms(500);
            PORTB |= (1 << PB4);     // D3 off again

            // Turn on D4 for 500 ms, then turn it off again
            PORTB &= ~(1 << PB5);
            _delay_ms(500);
            PORTB |= (1 << PB5);     // D4 off again

            // Turn on D5 for 500 ms, then turn it off again
            PORTC &= ~(1 << PC0);
            _delay_ms(500);
            PORTC |= (1 << PC0);     // D5 off again

            // Turn on D6 for 500 ms, then turn it off again
            PORTC &= ~(1 << PC1);
            _delay_ms(500);
            PORTC |= (1 << PC1);     // D6 off again

            // Turn on D7 for 500 ms, then turn it off again
            PORTC &= ~(1 << PC2);
            _delay_ms(500);
            PORTC |= (1 << PC2);     // D7 off again

            // Turn on D8 for 500 ms, then turn it off again
            PORTB &= ~(1 << PB0);
            _delay_ms(500);
            PORTB |= (1 << PB0);     // D8 off again

            // Turn on D9 for 500 ms, then turn it off again
            PORTD &= ~(1 << PD7);
            _delay_ms(500);
            PORTD |= (1 << PD7);     // D9 off again

            // Turn on D10 for 500 ms, then turn it off again
            PORTD &= ~(1 << PD6);
            _delay_ms(500);
            PORTD |= (1 << PD6);     // D10 off again

            // Turn on D11 for 500 ms, then turn it off again
            PORTD &= ~(1 << PD5);
            _delay_ms(500);
            PORTD |= (1 << PD5);     // D11 off again
}