#include "LEDController/LEDController.h"

/**
 * @class LEDController
 * @brief A class to control RGB LEDs and Neopixel strips.
 * 
 * This class provides methods to control both analog RGB LEDs and Neopixel LED strips.
 */

/**
 * @brief Constructor for the LEDController class.
 * 
 * @param rPin The pin connected to the red channel of the RGB LED.
 * @param gPin The pin connected to the green channel of the RGB LED.
 * @param bPin The pin connected to the blue channel of the RGB LED.
 * @param ledPin The pin connected to the Neopixel strip.
 * @param ledCount The number of LEDs in the Neopixel strip.
 */
LEDController::LEDController(int rPin, int gPin, int bPin, int ledPin, int ledCount)
    : rPin(rPin), gPin(gPin), bPin(bPin), strip(ledCount, ledPin, NEO_GRB + NEO_KHZ800), ledCount(ledCount) {}

/**
 * @brief Initializes the Neopixel strip.
 * 
 * This method sets up the Neopixel strip, initializes its brightness, and clears any previous colors.
 */
void LEDController::begin()
{
    strip.begin();               // Initialize the Neopixel strip.
    strip.setBrightness(50);     // Set the brightness to 50%.
    strip.show();                // Clear the strip by showing no color.
}

/**
 * @brief Sets the color of an analog RGB LED.
 * 
 * @param red The intensity of the red channel (0-255).
 * @param green The intensity of the green channel (0-255).
 * @param blue The intensity of the blue channel (0-255).
 */
void LEDController::setRGBColor(int red, int green, int blue)
{
    analogWrite(rPin, red);      // Set the red channel intensity.
    analogWrite(gPin, green);    // Set the green channel intensity.
    analogWrite(bPin, blue);     // Set the blue channel intensity.
}

/**
 * @brief Sets the color of all LEDs in the Neopixel strip.
 * 
 * @param red The intensity of the red channel (0-255).
 * @param green The intensity of the green channel (0-255).
 * @param blue The intensity of the blue channel (0-255).
 */
void LEDController::setNeopixelColor(int red, int green, int blue)
{
    for (int i = 0; i < ledCount; i++) // Loop through all LEDs in the strip.
    {
        strip.setPixelColor(i, strip.Color(red, green, blue)); // Set the color for each LED.
    }
    strip.show(); // Update the strip to display the new colors.
}