#include "Sensors/SoilSensor.h"

SoilSensor::SoilSensor(int pin) : pin(pin) {}

int SoilSensor::read()
{
    return analogRead(pin);
}