#include <avr/io.h>
#include <stdbool.h>
#include "button.h"

extern volatile uint8_t Sekunde;   // muss in einer anderen Datei definiert sein

void initButton(){
DDRD &= ~(1 << PD3);
PORTD |= (1 << PD3);
EICRA = 0;
EIMSK |= (1 << INT1);	
}

bool button_4_pressed(void){
    DDRD &= ~(1 << PD4);
    PORTD |= (1 << PD4);
    return !(PIND & (1 << PD4));
}

bool button_3_pressed(void){
    DDRD &= ~(1 << PD3);
    PORTD |= (1 << PD3);
    return !(PIND & (1 << PD3));
}

bool button_2_pressed(void){
    DDRD &= ~(1 << PD2);
    PORTD |= (1 << PD2);
    return !(PIND & (1 << PD2));
}

bool entprellt(void){
    static uint16_t alt = 0;
    uint16_t neu = ((uint16_t)Sekunde << 8) | TCNT2;

    if ((uint16_t)(neu - alt) < 64) {   // ca. 20 ms bei 1 MHz, Prescaler 128
        return false;
    }

    alt = neu;
    return true;
}

int button_pressed(void){
    if(button_4_pressed()){
        if(entprellt()){
            button_4_getter = true;
            return 4;
        } else {
            button_4_getter = false;
        }
    } else if(button_2_pressed()){
        if(entprellt()){
            return 2;
        }
    }
    return 1;
}