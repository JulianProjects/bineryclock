#include <avr/io.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <util/delay.h> 

#include "timer.h"
#include "button.h"
#include "LED.h"
#include "sleep_mode.h"
#include "pwm.h"
#include "modes.h"
#include "test_platine.h"
#include "uart.h"

volatile bool neue_sekunde_flag = 0;
volatile uint8_t Sekunde = 0;
volatile uint8_t Minute = 12;
volatile uint8_t Stunde = 13;
volatile uint8_t sleep_mode_active = 0;
int entpreller_first_press = 0;
int entpreller_second_press = 0;
int brightness = 100;
bool button_4_getter = false;

volatile int modus = 1;

int main(void)
{
    init_LED();
    initTimer();
    initButton();
    init_sleep_mode();
    sei();

    set_all_led_off();
    while (1)
    {
    handle_mode();
    }
}