#ifndef LightSensor_h
#define LightSensor_h

#include <Arduino.h>

class LightSensor
{
public:
    LightSensor(int pin);
    int read();
    int pin;
};

#endif