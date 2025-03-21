#include <LiquidCrystal.h>      // Include the LiquidCrystal library for LCD display
#include <Arduino.h>            // Include the standard Arduino functions
#include <Adafruit_NeoPixel.h>  // Include the Adafruit NeoPixel library for controlling RGB LEDs

// Pin configurations for various components
#define LED_PIN 5               // Pin connected to the NeoPixel LED strip
#define LED_COUNT 16            // Number of NeoPixel LEDs in the strip
#define WATER_PUMP_PIN 11       // Pin controlling the water pump
#define SOIL_SENSOR_PIN A0      // Pin for the soil moisture sensor
#define LIGHT_SENSOR_PIN A1     // Pin for the light intensity sensor
#define R_PIN 2                 // Pin for the Red component of the RGB LED
#define G_PIN 3                 // Pin for the Green component of the RGB LED
#define B_PIN 4                 // Pin for the Blue component of the RGB LED

// Initialize NeoPixel strip
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800); 
// Initialize LCD with specified pins for controlling
LiquidCrystal lcd(6, 7, 8, 9, 10, 12);

// Class to manage the soil sensor
class SoilSensor {
public:
    int read() {
        return analogRead(SOIL_SENSOR_PIN);  // Read the soil moisture level
    }
};

// Class to manage the light sensor
class LightSensor {
public:
    int read() {
        return analogRead(LIGHT_SENSOR_PIN); // Read the light intensity level
    }
};

// Class to manage the water pump
class WaterPump {
public:
    void setSpeed(int speed) {
        analogWrite(WATER_PUMP_PIN, speed);  // Set the water pump speed (0-255 range)
    }
};

// Class to manage the RGB LED (3 individual colors)
class LEDController {
public:
    void setRGBColor(int red, int green, int blue) {
        analogWrite(R_PIN, red);     // Set Red color intensity
        analogWrite(G_PIN, green);   // Set Green color intensity
        analogWrite(B_PIN, blue);    // Set Blue color intensity
    }

    void setNeopixelColor(int red, int green, int blue) {
        for (int i = 0; i < LED_COUNT; i++) {   // Loop through each NeoPixel LED
            strip.setPixelColor(i, strip.Color(red, green, blue)); // Set color for each LED
        }
        strip.show();  // Update the strip to show the new color
    }

    void begin() {
        strip.begin();             // Initialize the NeoPixel strip
        strip.setBrightness(50);   // Set the brightness of the NeoPixel strip to 50%
        strip.show();              // Initialize all pixels to 'off'
    }
};

// Class to manage the LCD display
class Display {
public:
    void begin() {
        lcd.begin(16, 2);  // Initialize the LCD to 16x2 character display
    }

    void showValues(int soilValue, int lightValue) {
        lcd.setCursor(0, 0);       // Set cursor to first row, first column
        lcd.print("Soil: ");
        lcd.print(soilValue);      // Display soil moisture value on LCD

        lcd.setCursor(0, 1);       // Set cursor to second row, first column
        lcd.print("Light: ");
        lcd.print(lightValue);     // Display light intensity value on LCD
    }
};

// Main class to manage the Smart Garden system
class SmartGardenController {
private:
    SoilSensor soilSensor;      // Instance of the soil sensor class
    LightSensor lightSensor;    // Instance of the light sensor class
    WaterPump waterPump;        // Instance of the water pump class
    LEDController ledController; // Instance of the LED controller class
    Display display;            // Instance of the display class

public:
    void begin() {
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

    void update() {
        int soilVal = soilSensor.read();      // Read the soil moisture value
        int lightVal = lightSensor.read();    // Read the light intensity value

        display.showValues(soilVal, lightVal); // Display the sensor values on LCD

        Serial.print("Soil: "); Serial.println(soilVal); // Display soil value on Serial monitor
        Serial.print("Light: "); Serial.println(lightVal); // Display light value on Serial monitor

        controlWaterPumpAndLEDs(soilVal);     // Control water pump and LEDs based on soil value
        controlGrowLight(lightVal);           // Control grow light based on light value
    }

    // Function to control water pump and RGB LEDs based on soil moisture
    void controlWaterPumpAndLEDs(int soilValue) {
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
    void controlGrowLight(int lightValue) {
        if (lightValue < 20) {                  // If light intensity is too low
            Serial.println("Grow light ON");     // Print grow light ON message
            ledController.setNeopixelColor(255, 165, 0); // Turn on grow light with warm orange color
        } else {
            Serial.println("Grow light OFF");    // Print grow light OFF message
            ledController.setNeopixelColor(0, 0, 0);   // Turn off the NeoPixel LEDs (grow light off)
        }
    }
};

SmartGardenController garden;  // Create an instance of the SmartGardenController class

void setup() {
    garden.begin();  // Initialize the Smart Garden system
}

void loop() {
    garden.update();  // Continuously update the system by reading sensors and controlling devices
    delay(1000);      // Delay for 1 second before repeating the loop
}
