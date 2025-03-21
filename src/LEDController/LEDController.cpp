#include <LEDController/LEDController.h>

void LEDController::setRGBColor(int red, int green, int blue) {
    analogWrite(R_PIN, red);     // Set Red color intensity
    analogWrite(G_PIN, green);   // Set Green color intensity
    analogWrite(B_PIN, blue);    // Set Blue color intensity
}

void LEDController::setNeopixelColor(int red, int green, int blue) {
    for (int i = 0; i < LED_COUNT; i++) {   // Loop through each NeoPixel LED
        strip.setPixelColor(i, strip.Color(red, green, blue)); // Set color for each LED
    }
    strip.show();  // Update the strip to show the new color
}

void LEDController::begin() {
    strip.begin();             // Initialize the NeoPixel strip
    strip.setBrightness(50);   // Set the brightness of the NeoPixel strip to 50%
    strip.show();              // Initialize all pixels to 'off'
}