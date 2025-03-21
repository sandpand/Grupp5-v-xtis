#include "Sensors/LightSensor.h"

LightSensor::LightSensor(int pin) : pin(pin) {}

int LightSensor::read()
{
    return analogRead(pin);
}