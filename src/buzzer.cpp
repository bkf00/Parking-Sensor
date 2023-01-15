#include "buzzer.h"

unsigned long startBeep;


void GenerateTone(int state)
{
    if(state == 3)
    {
        tone(BUZZER, 500); // generate a 500kHz tone on the buzzer pin
        delay(3000);
        noTone(BUZZER); 
    }
    else if(state == 2){
        if(millis() - startBeep >= 1000)
        {
            startBeep = millis();
            tone(BUZZER, 500,1000); // generate a 500kHz tone on the buzzer pin
        }
    }
    else if(state == 1){
        if(millis() - startBeep >= 2000)
        {
            startBeep = millis();
            tone(BUZZER, 500,2000); // generate a 500kHz tone on the buzzer pin
        }
    }
    else if(state == 0){
        noTone(BUZZER);
    }
}
    
    