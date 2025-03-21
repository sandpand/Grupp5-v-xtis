#include <Sensors/SoilSensor.h>

int SoilSensor::read() {
    return analogRead(SOIL_SENSOR_PIN);  // Read the soil moisture level
}