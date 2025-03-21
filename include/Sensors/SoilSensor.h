#ifndef SoilSensor_h
#define SoilSensor_h

#include <Arduino.h>

class SoilSensor
{
public:
    SoilSensor(int pin);
    int read();
    int pin;
};

#endif