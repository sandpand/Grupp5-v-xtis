#include "Sensors/SoilSensor.h"
#include <Arduino.h>

SoilSensor::SoilSensor(int pin) : pin(pin) {}

/**
 * @brief Reads the current value from the soil sensor.
 *
 * This function reads the analog value from the pin connected to the soil sensor.
 * The value returned is an integer representing the sensor's reading.
 *
 * @return int The analog value read from the soil sensor.
 */
int SoilSensor::read()
{
    return analogRead(pin);
}