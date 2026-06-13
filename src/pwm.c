#include <avr/io.h>


void set_pwm_pb1(int pwm_value){
    TCCR1A = (1 << WGM10)
           | (1 << COM1A1);   // OC1A (PB1)

    TCCR1B = (1 << WGM12)
           | (1 << CS11);

    OCR1A = pwm_value;        // Duty Cycle für PB1
}