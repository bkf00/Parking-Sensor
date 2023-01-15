#include "display.h"

void DisplayOnScreen(LiquidCrystal_I2C lcd, unsigned int frontDistance, unsigned int backDistance)
{
    lcd.setCursor(0,0);
    lcd.print("Front : ");
    lcd.print(frontDistance);
    lcd.print (" cm");
    lcd.setCursor(1, 1);
    lcd.print("Back : ");
    lcd.print(backDistance);
    lcd.print (" cm");
}

