#include <Sensors/LightSensor.h>
int LightSensor::read() {
    return analogRead(LIGHT_SENSOR_PIN); // Read the light intensity level
}