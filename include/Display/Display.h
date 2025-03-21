#ifndef Display_h
#define Display_h

#include <Arduino.h>
#include <LiquidCrystal.h>
/**
 * @class Display
 * @brief Handles the LCD display for showing sensor values.
 *
 * This class is responsible for initializing and updating the LCD display
 * with the soil moisture and light sensor values.
 */
class Display
{
private:
    LiquidCrystal lcd;

public:
    Display(int rs, int en, int d4, int d5, int d6, int d7);
    void begin();
    void showValues(int soilValue, int lightValue);
};

#endif