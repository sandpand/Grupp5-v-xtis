#ifndef Display_h
#define Display_h

#include <Arduino.h>
#include <LiquidCrystal.h>

class Display
{
private:
    LiquidCrystal lcd;

public:
    Display();
    void begin();
    void showValues(int soilValue, int lightValue);
};

#endif