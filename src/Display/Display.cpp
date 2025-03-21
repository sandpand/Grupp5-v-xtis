#include "Display/Display.h"

Display::Display(int rs, int en, int d4, int d5, int d6, int d7)
    : lcd(rs, en, d4, d5, d6, d7) {}

void Display::begin()
{
    lcd.begin(16, 2);
}

void Display::showValues(int soilValue, int lightValue)
{
    lcd.setCursor(0, 0);
    lcd.print("Soil value: ");
    lcd.print("    ");
    lcd.setCursor(12, 0);
    lcd.print(soilValue);

    lcd.setCursor(0, 1);
    lcd.print("Light value: ");
    lcd.print("    ");
    lcd.setCursor(13, 1);
    lcd.print(lightValue);
}