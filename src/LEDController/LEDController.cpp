#include "LEDController/LEDController.h"

LEDController::LEDController(int rPin, int gPin, int bPin, int ledPin, int ledCount)
    : rPin(rPin), gPin(gPin), bPin(bPin), strip(ledCount, ledPin, NEO_GRB + NEO_KHZ800), ledCount(ledCount) {}

void LEDController::begin()
{
    strip.begin();
    strip.setBrightness(50);
    strip.show();
}

void LEDController::setRGBColor(int red, int green, int blue)
{
    analogWrite(rPin, red);
    analogWrite(gPin, green);
    analogWrite(bPin, blue);
}

void LEDController::setNeopixelColor(int red, int green, int blue)
{
    for (int i = 0; i < ledCount; i++)
    {
        strip.setPixelColor(i, strip.Color(red, green, blue));
    }
    strip.show();
}