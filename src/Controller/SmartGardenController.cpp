#include <Controller/SmartGardenController.h>

void SmartGardenController::begin() {
    pinMode(SOIL_SENSOR_PIN, INPUT);   // Set soil sensor pin as input
    pinMode(LIGHT_SENSOR_PIN, INPUT);  // Set light sensor pin as input
    pinMode(WATER_PUMP_PIN, OUTPUT);   // Set water pump pin as output
    pinMode(R_PIN, OUTPUT);            // Set RGB red pin as output
    pinMode(G_PIN, OUTPUT);            // Set RGB green pin as output
    pinMode(B_PIN, OUTPUT);            // Set RGB blue pin as output

    ledController.begin();            // Initialize the LED controller (NeoPixel)
    display.begin();                  // Initialize the LCD display
    Serial.begin(9600);               // Initialize serial communication at 9600 baud rate
}

void SmartGardenController::update() {
    int soilVal = soilSensor.read();      // Read the soil moisture value
    int lightVal = lightSensor.read();    // Read the light intensity value

    display.showValues(soilVal, lightVal); // Display the sensor values on LCD

    Serial.print("Soil: "); Serial.println(soilVal); // Display soil value on Serial monitor
    Serial.print("Light: "); Serial.println(lightVal); // Display light value on Serial monitor

    controlWaterPumpAndLEDs(soilVal);     // Control water pump and LEDs based on soil value
    controlGrowLight(lightVal);           // Control grow light based on light value
}

// Function to control water pump and RGB LEDs based on soil moisture
void SmartGardenController::controlWaterPumpAndLEDs(int soilValue) {
    if (soilValue > 950) {
        waterPump.setSpeed(200);         // Turn on water pump at 80% speed
        ledController.setRGBColor(0, 0, 255); // Set LED color to Blue (watering indicator)
    } else if (soilValue >= 450) {
        waterPump.setSpeed(123);         // Turn on water pump at 50% speed
        ledController.setRGBColor(255, 0, 0); // Set LED color to Red (warning indicator)
    } else {
        waterPump.setSpeed(0);           // Turn off water pump (no need for water)
        ledController.setRGBColor(0, 255, 0); // Set LED color to Green (healthy soil)
    }
}

// Function to control the grow light based on light intensity
void SmartGardenController::controlGrowLight(int lightValue) {
    if (lightValue < 20) {                  // If light intensity is too low
        Serial.println("Grow light ON");     // Print grow light ON message
        ledController.setNeopixelColor(255, 165, 0); // Turn on grow light with warm orange color
    } else {
        Serial.println("Grow light OFF");    // Print grow light OFF message
        ledController.setNeopixelColor(0, 0, 0);   // Turn off the NeoPixel LEDs (grow light off)
    }
}