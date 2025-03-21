#include "Controller/SmartGardenController.h"

SmartGardenController::SmartGardenController(int soilPin, int lightPin, int waterPin, int rPin, int gPin, int bPin, int ledPin, int ledCount, int rs, int en, int d4, int d5, int d6, int d7)
    : soilSensor(soilPin), lightSensor(lightPin), waterPump(waterPin), ledController(rPin, gPin, bPin, ledPin, ledCount), display(rs, en, d4, d5, d6, d7) {}

void SmartGardenController::begin()
{
    pinMode(soilSensor.pin, INPUT);
    pinMode(lightSensor.pin, INPUT);
    pinMode(waterPump.pin, OUTPUT);
    ledController.begin();
    display.begin();
    Serial.begin(9600);
}

void SmartGardenController::update()
{
    int soilVal = soilSensor.read();
    int lightVal = lightSensor.read();

    display.showValues(soilVal, lightVal);

    if (soilVal > 950)
    {
        waterPump.setSpeed(true);
        ledController.setRGBColor(0, 0, 255);
        delay(1000);
    }
    else if (soilVal >= 450)
    {
        waterPump.setSpeed(false);
        ledController.setRGBColor(255, 0, 0);
    }
    else
    {
        waterPump.setSpeed(false);
        ledController.setRGBColor(0, 255, 0);
    }

    if (lightVal < 40)
    {
        ledController.setNeopixelColor(255, 165, 0);
    }
    else
    {
        ledController.setNeopixelColor(0, 0, 0);
    }

    delay(1000);
}