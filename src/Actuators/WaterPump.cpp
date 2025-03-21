#include "Actuators/WaterPump.h"

WaterPump::WaterPump(int pin) : pin(pin) {}

/**
 * @brief Sets the speed of the water pump by controlling its state.
 *
 * This function sets the state of the water pump to either HIGH or LOW
 * based on the provided boolean value. A HIGH state typically turns the
 * pump on, while a LOW state turns it off. The function uses the
 * digitalWrite function to control the pin connected to the pump.
 * If we had a MOSFET instead of a relay, we would use analogWrite to control
 * the speed of the pump.
 *
 * @param state A boolean value representing the desired state of the pump:
 *              - `true` to turn the pump on (HIGH state).
 *              - `false` to turn the pump off (LOW state).
 */
void WaterPump::setSpeed(bool state)
{
    digitalWrite(pin, state ? HIGH : LOW);
}