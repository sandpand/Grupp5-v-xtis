#include "Actuators/WaterPump.h"

WaterPump::WaterPump(int pin) : pin(pin) {}

void WaterPump::setSpeed(bool state)
{
    digitalWrite(pin, state ? HIGH : LOW);
}