#include <Arduino.h>
#include <display.h>
#include <buzzer.h>
#include <NewPing.h>

LiquidCrystal_I2C lcd(0x27,16,2);
int state; // 0 = distance bigger than 2m , 1 = far distance , 2 = medium distance, 3 = close distance
#define ECHO_1           2
#define TRIGGER_1        3
#define ECHO_2           4
#define TRIGGER_2        5
#define in1              8
#define in2              9
#define in3              10
#define in4              11
#define enA              12
#define enB              13

#define SONAR_NUM 2      // Number of sensors.
#define MAX_DISTANCE 300 // Maximum distance (in cm) to ping.

NewPing sonar[SONAR_NUM] = {   // Sensor object array.
  NewPing(TRIGGER_1, ECHO_1, MAX_DISTANCE), // Each sensor's trigger pin, echo pin, and max distance to ping.
  NewPing(TRIGGER_2, ECHO_2, MAX_DISTANCE)
};

unsigned int distanceFront;
unsigned int distanceBack;
unsigned int distance;
String distanceToMeasure;


void setup() 
{

  Serial.begin(9600);
  pinMode(BUZZER,OUTPUT);
  lcd.init();
  lcd.clear();
  lcd.backlight();
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  analogWrite(enA, 200);
  analogWrite(enB, 200);
  distanceToMeasure = "Front";
}

void loop() 
{
    delay(50);
    unsigned int uS1 = sonar[0].ping(); 
    unsigned int uS2 = sonar[1].ping(); 
    distanceFront = uS1/58;
    distanceBack = uS2/58;
    DisplayOnScreen(lcd, distanceFront, distanceBack);
    if(distanceToMeasure == "Front")
    {
        distance = distanceFront;
        Serial.println(distanceToMeasure);
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    }
    else
    {
        distance = distanceBack;
        Serial.println(distanceToMeasure);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
    }
    if(distance <= 200 && distance >=100)
    {
        state=1;
    }
    else if(distance <= 100 && distance >=15)
    {
        state=2;
    }
    else if(distance <= 15 && distance >=1)
    {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        state=3;
    }
    else
    {
        state=0;
    }
    GenerateTone(state);
    if(state == 3)
    {
        if(distanceToMeasure == "Front")
            distanceToMeasure = "Back";
            else
            distanceToMeasure = "Front";
    }
    Serial.println(state);
}