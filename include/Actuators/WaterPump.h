#ifndef WaterPump_h
#define WaterPump_h

#include <Arduino.h>

class WaterPump
{
public:
    WaterPump(int pin);
    void setSpeed(bool state);
    int pin;
};

#endif