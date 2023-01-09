#include <Arduino.h>
#include <display.h>
#include <distance.h>
#include <buzzer.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int state; // 0 = stopped , 1 = far distance , 2 = medium distance, 3 = close distance
#define ECHO_1           2
#define TRIGGER_1        3
#define ECHO_2           4
#define TRIGGER_2        5
#define MOTOR_OUT_2      8
#define MOTOR_IN_2       9
#define MOTOR_PWM_2      10
#define MOTOR_OUT_1      11
#define MOTOR_IN_1       12
#define MOTOR_PWM_1      13
float distanceFront;
float distanceBack;


void setup() 
{
  Serial.begin(9600);
  pinMode(BUZZER,OUTPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void loop() 
{
    distanceFront = MeasureDistance(TRIGGER_1,ECHO_1);
    distanceBack = MeasureDistance(TRIGGER_2,ECHO_2);
    DisplayOnScreen(lcd, distanceFront, distanceBack);
    if((distanceBack <= 200 && distanceBack >=100) || (distanceFront <= 200 && distanceFront>=100))
    {
        state=1;
    }
    else if((distanceBack <= 100 && distanceBack >=50) || (distanceFront <= 100 && distanceFront>=50))
    {
        state=2;
    }
    else if((distanceBack <= 50 && distanceBack >=1) || (distanceFront <= 50 && distanceFront>=1))
    {
        state=3;
    }
    GenerateTone(state);
  
}