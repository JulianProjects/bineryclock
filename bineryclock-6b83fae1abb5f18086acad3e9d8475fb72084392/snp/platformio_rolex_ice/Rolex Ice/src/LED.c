#include <avr/io.h>
#include <util/delay.h>
#include "LED.h"
#include "timer.h"


void init_LED(void){
	// Set PB1, PB0, PB2, PB3, PB4, PB5 as outputs
    DDRB |= (1 << PB1) | (1 << PB0) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5);

    // Set PC0, PC1, PC2 as outputs
    DDRC |= (1 << PC0) | (1 << PC1) | (1 << PC2);

    // Set PD5, PD6, PD7 as outputs
    DDRD |= (1 << PD5) | (1 << PD6) | (1 << PD7);

    // PB1 is the common HIGH line for the LEDs
    PORTB |= (1 << PB1);
}

void set_all_led_off(void){
	PORTB |= (1 << PB0) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5);
    PORTC |= (1 << PC0) | (1 << PC1) | (1 << PC2);
    PORTD |= (1 << PD5) | (1 << PD6) | (1 << PD7);
}

void set_all_led_on(void){
    PORTB &= ~((1 << PB0) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5));
    PORTC &= ~((1 << PC0) | (1 << PC1) | (1 << PC2));
    PORTD &= ~((1 << PD5) | (1 << PD6) | (1 << PD7));
}

void display_minutes(int minutes){
	// Turn on D3 for 500 ms, then turn it off again
	uint8_t minutes_binary = (uint8_t)minutes;
	for(int led = 2; led <= 5; led++){
		if((minutes_binary >> (led - 2)) & 0b1){
			PORTB &= ~(1 << led);
		}else{
			PORTB |= (1 << led);
		}
	}
	
	for(int led = 0; led <= 1; led++){
		if(minutes_binary >> (led+4) & 0b1){
			PORTC &= ~(1 << led);
		}else{
			PORTC |= (1 << led);
		}
	}
}

int display_pm(int hours){
	if(hours >= 12){
		PORTC &= ~(1 << PC2);
		return hours - 12;
	} else {
		PORTC |= (1 << PC2);
		return hours;
	}
}

void turn_off_hours(void){
	PORTC |= (1 << PC2); // PM off
	PORTB |= (1 << 0); // PB0 off
	for (int led = 0; led < 3; led++) {
		PORTD |= (1 << (7 - led));
	}
}

void display_hours(){
	int hours_copy = Stunde;
	if(Stunde >= 12){
		PORTC &= ~(1 << PC2);
		hours_copy -= 12;
	} else {
		PORTC |= (1 << PC2);
	}

	uint8_t hours_binary = (uint8_t)hours_copy;
	if(hours_binary & 0b1){
		PORTB &= ~(1 << 0);
	}else{
		PORTB |= (1 << 0);
	} 
	for (int led = 0; led < 3; led++) {
		if ((hours_binary >> (led + 1)) & 0b1) {
			PORTD &= ~(1 << (7 - led));
		} else {
			PORTD |= (1 << (7 - led));
		}
	} 
}

void display_minutes_hours(void){
	if(neue_sekunde_flag){
        current_time();
        display_minutes(Minute);
		display_hours();
    }
}

void display_seconds(void){
	if(neue_sekunde_flag){
        current_time();
        display_minutes(Sekunde);
		turn_off_hours();
    }
}