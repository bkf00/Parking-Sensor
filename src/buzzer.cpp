#include "buzzer.h"

void GenerateTone(int state){
    if(state == 3){
        tone(BUZZER, 500);
        delay(300);
        noTone(BUZZER);
    }
    else if(state == 2){
        tone(BUZZER, 500);
        delay(1000);
        noTone(BUZZER); 
    }
    else if(state == 1){
        tone(BUZZER, 500);
        delay(2000);
        noTone(BUZZER);
    }
    else if(state == 0){
        noTone(BUZZER);
    }
    
}