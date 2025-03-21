"include <Actuators/WaterPump.h"

void WaterPump::setSpeed(int speed) {
    analogWrite(WATER_PUMP_PIN, speed);  // Set the water pump speed (0-255 range)
}