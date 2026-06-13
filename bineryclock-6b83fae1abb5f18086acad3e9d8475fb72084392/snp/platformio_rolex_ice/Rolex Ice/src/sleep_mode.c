#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <stdint.h>

#include "sleep_mode.h"
#include "LED.h"

extern volatile uint8_t sleep_mode_active;

// merkt sich alten Zustand von PD1
static volatile uint8_t pd1_last_state = 1;

void init_sleep_mode(void)
{
    DDRD &= ~(1 << PD1);
    PORTD |= (1 << PD1);

    pd1_last_state = (PIND & (1 << PD1)) ? 1 : 0;

    PCICR |= (1 << PCIE2);
    PCMSK2 |= (1 << PCINT17);
    PCIFR |= (1 << PCIF2);

    set_sleep_mode(SLEEP_MODE_PWR_SAVE);
}

ISR(PCINT2_vect)
{
    uint8_t current_state = (PIND & (1 << PD1)) ? 1 : 0;

    // nur auf fallende Flanke reagieren
    if (pd1_last_state && !current_state) {
        sleep_mode_active = !sleep_mode_active;
    }

    pd1_last_state = current_state;
}

void manage_sleep_mode(void)
{
    while (sleep_mode_active) {
        set_all_led_off();

        // warten bis Taste losgelassen wurde
        while (!(PIND & (1 << PD1))) {
            ;
        }

        sleep_enable();
        sleep_cpu();
        sleep_disable();
    }
}