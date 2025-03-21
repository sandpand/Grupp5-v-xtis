#ifndef LEDController_h
#define LEDController_h

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class LEDController
{
private:
    int rPin;
    int gPin;
    int bPin;
    Adafruit_NeoPixel strip;
    int ledCount;

public:
    LEDController(int rPin, int gPin, int bPin, int ledPin, int ledCount);
    void begin();
    void setRGBColor(int red, int green, int blue);
    void setNeopixelColor(int red, int green, int blue);
};

#endif