#ifndef SmartGardenController_h
#define SmartGardenController_h

#include <Arduino.h>

class SmartGardenController
{
private:
    class SoilSensor;
    class LightSensor;
    class WaterPump;
    class LEDController;
    class Display;

    void controlWaterPumpAndLEDs(int soilValue);
    void controlGrowLight(int lightValue);

public:
    void begin();
    void update();
};

#endif