#include "Sensors/LightSensor.h"

LightSensor::LightSensor(int pin) : pin(pin) {}

/**
 * @brief Reads the current value from the light sensor.
 * 
 * This function reads the analog value from the pin connected to the light sensor.
 * The value returned is typically in the range of 0 to 1023, representing the 
 * intensity of the light detected by the sensor.
 * 
 * @return int The analog value read from the light sensor.
 */
int LightSensor::read()
{
    return analogRead(pin);
}