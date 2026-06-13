#include <avr/io.h>
#include <stdbool.h>

#include "modes.h"
#include "button.h"
#include "LED.h"
#include "sleep_mode.h"
#include "pwm.h"

volatile extern int modus;
extern int brightness;
extern volatile uint8_t sleep_mode_active;

void handle_mode_1(void)
{
    display_minutes_hours();
    modus = button_pressed();
}

void handle_mode_2(void)
{
    display_seconds();
    modus = button_pressed();

    if (modus == 1){
        modus = 2;
    } 
    else if (modus == 2){
        modus = 1;
    }
}

void handle_mode_4(void)
{
    set_all_led_on();
    modus = button_pressed();

    if (modus == 1){
        modus = 4;
    } 
    else if (modus == 4){
        if (button_4_getter){
            brightness -= 25;
            set_pwm_pb1(brightness);
        }

        if (brightness <= 0){
            brightness = 100;
            modus = 1;
        }
    }
}

void handle_mode_3(void)
{
    manage_sleep_mode();
}

void handle_mode(void)
{
    switch(modus)
    {
        case 1:
            handle_mode_1();
            break;

        case 2:
            handle_mode_2();
            break;

        case 3:

            handle_mode_3();
            break;

        case 4:

            handle_mode_4();
            break;

        default: break;
    }
}