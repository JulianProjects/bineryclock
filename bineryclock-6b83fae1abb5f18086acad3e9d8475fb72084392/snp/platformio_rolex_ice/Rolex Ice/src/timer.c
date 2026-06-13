#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "timer.h"

void initTimer()
{
    ASSR |= (1<<AS2);

    TCNT2 = 0;

    TCCR2B = (1<<CS22)|(1<<CS20);

    while (ASSR & ((1<<TCN2UB)|(1<<TCR2AUB)|(1<<TCR2BUB)));

    TIMSK2 = (1<<TOIE2);
}

ISR(TIMER2_OVF_vect)
{
    neue_sekunde_flag = 1;
}

void current_time(){
    if (!sleep_mode_active) {
    neue_sekunde_flag = 1;
    }
    neue_sekunde_flag = 0;
    Sekunde++;
    if(Sekunde >= 60)
    {
        Sekunde = 0;
        Minute++;
    }
    if(Minute >= 60)
    {
        Minute = 0;
        Stunde++;
    }
    if(Stunde >= 24)
        Stunde = 0;
}