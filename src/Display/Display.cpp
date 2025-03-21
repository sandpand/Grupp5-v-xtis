#include <Display/Display.h>

void Display::begin() {
    lcd.begin(16, 2);  // Initialize the LCD to 16x2 character display
}

void Display::showValues(int soilValue, int lightValue) {
    lcd.setCursor(0, 0);       // Set cursor to first row, first column
    lcd.print("Soil: ");
    lcd.print(soilValue);      // Display soil moisture value on LCD

    lcd.setCursor(0, 1);       // Set cursor to second row, first column
    lcd.print("Light: ");
    lcd.print(lightValue);     // Display light intensity value on LCD
}