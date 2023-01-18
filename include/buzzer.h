#include "Arduino.h"
#define BUZZER  6
#define LED1_GREEN       22
#define LED1_RED         23
#define LED2_GREEN       24
#define LED2_RED         25
#define LED3_GREEN       26
#define LED3_RED         27

void GenerateTone(int state);
void setup_timer_3();

void LEDIndicators(int state);