// LED display implementation for binary clock.
// Controls LED output on ports B, C, and D for time display.

#include <avr/io.h>
#include <stdint.h>
#include <util/delay.h>

#include "led.h"
#include "timer.h"

// LED pin masks for different ports.
static const uint8_t kPortBLedMask = (1 << PB0) | (1 << PB2) |
                                      (1 << PB3) | (1 << PB4) | (1 << PB5);
static const uint8_t kPortCLedMask = (1 << PC0) | (1 << PC1) | (1 << PC2);
static const uint8_t kPortDLedMask = (1 << PD5) | (1 << PD6) | (1 << PD7);

void InitLed(void) {
  // Set PB0, PB2-PB5 as outputs (PB1 is common HIGH line).
  DDRB |= (1 << PB0) | (1 << PB2) | (1 << PB3) | (1 << PB4) | (1 << PB5);

  // Set PC0-PC2 as outputs.
  DDRC |= (1 << PC0) | (1 << PC1) | (1 << PC2);

  // Set PD5-PD7 as outputs.
  DDRD |= (1 << PD5) | (1 << PD6) | (1 << PD7);

  // PB1 is the common HIGH line for the LEDs.
  PORTB |= (1 << PB1);
}

void SetAllLedsOff(void) {
  // Set all LED pins to HIGH (active low, so LEDs are off).
  PORTB |= kPortBLedMask;
  PORTC |= kPortCLedMask;
  PORTD |= kPortDLedMask;
}

void SetAllLedsOn(void) {
  // Set all LED pins to LOW (active low, so LEDs are on).
  PORTB &= ~kPortBLedMask;
  PORTC &= ~kPortCLedMask;
  PORTD &= ~kPortDLedMask;
}

void DisplayMinutes(uint8_t minutes) {
  // Convert minutes to binary and display on 6 LED pins.
  // Pins: PB2-PB5 (4 bits) and PC0-PC1 (2 bits) = 6 bits total.
  uint8_t minutes_binary = minutes & 0x3F;  // Mask to 6 bits (0-63).
  
  // Display bits 0-3 on PB2-PB5.
  for (int led = 2; led <= 5; ++led) {
    if ((minutes_binary >> (led - 2)) & 0x01) {
      PORTB &= ~(1 << led);
    } else {
      PORTB |= (1 << led);
    }
  }
  
  // Display bits 4-5 on PC0-PC1.
  for (int led = 0; led <= 1; ++led) {
    if ((minutes_binary >> (led + 4)) & 0x01) {
      PORTC &= ~(1 << led);
    } else {
      PORTC |= (1 << led);
    }
  }
}

void DisplayHours(void) {
  // Implementation placeholder.
  // TODO: Implement hour display logic.
}

void DisplayMinutesAndHours(void) {
  // Implementation placeholder.
  // TODO: Implement minutes and hours display logic.
}

void DisplaySeconds(void) {
  // Implementation placeholder.
  // TODO: Implement seconds display logic.
}}

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