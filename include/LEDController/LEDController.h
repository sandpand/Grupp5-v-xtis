#ifndef LEDController_h
#define LEDController_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class LEDController
{
private:
    Adafruit_NeoPixel strip;

public:
    LEDController();
    void setRGBColor(int red, int green, int blue);
    void setNeopixelColor(int red, int green, int blue);
    void begin();
};

#endif