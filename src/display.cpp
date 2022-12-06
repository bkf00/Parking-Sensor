#include "display.h"

void DisplayOnScreen(LiquidCrystal_I2C lcd, float frontDistance, float backDistance)
{
    lcd.setCursor(0,0);
    lcd.print("Front : ");
    lcd.print(frontDistance);
    lcd.setCursor(0, 1);
    lcd.print("Back : ");
    lcd.print(backDistance);
}

