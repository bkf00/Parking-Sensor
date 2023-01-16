#include "buzzer.h"

void setup_timer_3(){
    TCCR3A = 0b00000000; // we want CTC mode
    TCCR3B = 0x00; // initilize register with 0
    TCCR3B |= (1<<3); // we want CTC mode
    TCCR3B &= 0b11111000; // stop the timer
    TCNT3 = 0; // initializing timer at 0
    TIMSK3 = 0x00; // initialize the counter
    TIMSK3 = (1<<1); // activate the interrupt trggered when counter 3 reaches value in OCR3A
}

void my_delay(int ms_to_wait)//this function can measure up to 4194ms
{
    TCNT3 = 0; // initializing timer at 0
    OCR3A = int(15,626 * ms_to_wait); // the timer wil count up to value in OCR3A
    TCCR3B |= (1<<2) | (1<<0) ; // prescaler equals 1024
}

ISR(TIMER3_COMPA){
    TCCR3B &= 0b11111000; // stop the timer
    noTone(BUZZER);

}

void GenerateTone(int state){
    if(state == 3){
        tone(BUZZER, 500);
        my_delay(300);
    }
    else if(state == 2){
        tone(BUZZER, 500);
        my_delay(700);
    }
    else if(state == 1){
        tone(BUZZER, 500);
        my_delay(1500);
    }
    else if(state == 0){
        noTone(BUZZER);
    }
}