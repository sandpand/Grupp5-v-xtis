#ifndef SmartGardenController_h
#define SmartGardenController_h

#include "Sensors/SoilSensor.h"
#include "Sensors/LightSensor.h"
#include "Actuators/WaterPump.h"
#include "LEDController/LEDController.h"
#include "Display/Display.h"

class SmartGardenController
{
private:
    SoilSensor soilSensor;
    LightSensor lightSensor;
    WaterPump waterPump;
    LEDController ledController;
    Display display;

public:
    SmartGardenController(int soilPin, int lightPin, int waterPin, int rPin, int gPin, int bPin, int ledPin, int ledCount, int rs, int en, int d4, int d5, int d6, int d7);
    void begin();
    void update();
};

#endif