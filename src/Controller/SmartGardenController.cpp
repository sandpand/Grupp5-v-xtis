#include "Controller/SmartGardenController.h"

/**
 * @brief Constructor for the SmartGardenController class.
 *
 * @param soilPin Pin connected to the soil moisture sensor.
 * @param lightPin Pin connected to the light sensor.
 * @param waterPin Pin connected to the water pump.
 * @param rPin Red pin for the RGB LED.
 * @param gPin Green pin for the RGB LED.
 * @param bPin Blue pin for the RGB LED.
 * @param ledPin Pin connected to the NeoPixel LED strip.
 * @param ledCount Number of LEDs in the NeoPixel strip.
 * @param rs Register select pin for the LCD display.
 * @param en Enable pin for the LCD display.
 * @param d4 Data pin 4 for the LCD display.
 * @param d5 Data pin 5 for the LCD display.
 * @param d6 Data pin 6 for the LCD display.
 * @param d7 Data pin 7 for the LCD display.
 */
SmartGardenController::SmartGardenController(int soilPin, int lightPin, int waterPin, int rPin, int gPin, int bPin, int ledPin, int ledCount, int rs, int en, int d4, int d5, int d6, int d7)
    : soilSensor(soilPin), lightSensor(lightPin), waterPump(waterPin), ledController(rPin, gPin, bPin, ledPin, ledCount), display(rs, en, d4, d5, d6, d7) {}

/**
 * @brief Initializes the SmartGardenController components.
 *
 * Sets up pin modes, initializes the LED controller, LCD display, and serial communication.
 */
void SmartGardenController::begin()
{
    // Configure sensor and pump pins
    pinMode(soilSensor.pin, INPUT);
    pinMode(lightSensor.pin, INPUT);
    pinMode(waterPump.pin, OUTPUT);

    // Initialize LED controller and LCD display
    ledController.begin();
    display.begin();

    // Start serial communication
    Serial.begin(9600);
}

/**
 * @brief Updates the system by reading sensor values and controlling components.
 *
 * Reads soil moisture and light sensor values, updates the LCD display, controls the water pump,
 * and adjusts LED colors based on sensor readings.
 */
void SmartGardenController::update()
{
    // Read sensor values
    int soilVal = soilSensor.read();
    int lightVal = lightSensor.read();

    // Display sensor values on the LCD
    display.showValues(soilVal, lightVal);

    // Control water pump and RGB LED based on soil moisture level
    if (soilVal > 950) // Very dry soil
    {
        waterPump.setSpeed(true);             // Turn on water pump
        ledController.setRGBColor(0, 0, 255); // Set RGB LED to blue
        delay(1000);                          // Wait for 1 second
    }
    else if (soilVal >= 450) // Moderate soil moisture
    {
        waterPump.setSpeed(false);            // Turn off water pump
        ledController.setRGBColor(255, 0, 0); // Set RGB LED to red
    }
    else // Sufficient soil moisture
    {
        waterPump.setSpeed(false);            // Turn off water pump
        ledController.setRGBColor(0, 255, 0); // Set RGB LED to green
    }

    // Control NeoPixel LED based on light level
    if (lightVal < 40) // Low light condition
    {
        ledController.setNeopixelColor(255, 165, 0); // Set NeoPixel to orange
    }
    else // Sufficient light
    {
        ledController.setNeopixelColor(0, 0, 0); // Turn off NeoPixel
    }

    // Delay to prevent rapid updates
    delay(1000);
}