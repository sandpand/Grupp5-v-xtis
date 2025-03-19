#include <LiquidCrystal.h>
#include <Arduino.h>

/**
 * @brief Displays soil and light sensor values on an LCD and Serial monitor.
 *
 * @param soilValue The current soil moisture reading.
 * @param lightValue The current light intensity reading.
 */
void displaySensorValues(int soilValue, int lightValue);

/**
 * @brief Controls the water pump and LED indicators based on soil moisture level.
 *
 * @param soilValue The current soil moisture reading.
 */
void controlWaterPumpAndLEDs(int soilValue);

/**
 * @brief Controls the grow light based on light intensity.
 *
 * @param lightValue The current light intensity reading.
 */
void controlGrowLight(int lightValue);

/**
 * @brief Sets the RGB LED color by adjusting individual color pins.
 *
 * @param red Intensity of red color (0-255).
 * @param green Intensity of green color (0-255).
 * @param blue Intensity of blue color (0-255).
 */
void setLEDColor(int red, int green, int blue);

// Pin configurations
int LED = 5;
int R_pin = 2;
int G_pin = 3;
int B_pin = 4;
int waterPump = 12;
int soilSensor = A0;
int lightSensor = A1;

// Sensor value variables
int soilVal;
int lightVal;

// Initialize LCD display with specified pins
LiquidCrystal lcd_1(6, 7, 8, 9, 10, 11);

/**
 * @brief Initializes the pins and serial communication.
 */
void setup()
{
  pinMode(soilSensor, INPUT);
  pinMode(lightSensor, INPUT);
  pinMode(waterPump, OUTPUT);
  pinMode(G_pin, OUTPUT);
  pinMode(R_pin, OUTPUT);
  pinMode(B_pin, OUTPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600);

  lcd_1.begin(16, 2);
}

/**
 * @brief Repeatedly reads sensor values, updates display, and controls devices.
 */
void loop()
{
  soilVal = analogRead(soilSensor);
  lightVal = analogRead(lightSensor);
  displaySensorValues(soilVal, lightVal); // Display sensor values on LCD and Serial monitor
  controlWaterPumpAndLEDs(soilVal);       // Control water pump and LEDs based on soil value

  controlGrowLight(lightVal); // Control grow light based on light value

  delay(1000); // Delay for 1 second
}

void displaySensorValues(int soilValue, int lightValue)
{
  lcd_1.setCursor(0, 0); // Set cursor to first row, first column
  lcd_1.print("Soil value: ");
  lcd_1.print("    ");    // Clear previous value
  lcd_1.setCursor(12, 0); // Set cursor to first row, 13th column
  lcd_1.print(soilValue);

  lcd_1.setCursor(0, 1); // Set cursor to second row, first column
  lcd_1.print("Light value: ");
  lcd_1.print("    ");    // Clear previous value
  lcd_1.setCursor(13, 1); // Set cursor to second row, 13th column
  lcd_1.print(lightValue);
}

void controlWaterPumpAndLEDs(int soilValue)
{
  if (soilValue > 950)
  {
    Serial.println("Water pump on");

    digitalWrite(waterPump, HIGH); // Turn on water pump
    setLEDColor(255, 0, 0);        // Set LED color to red
    delay(1000);
  }
  else if (soilValue >= 365)
  {
    setLEDColor(0, 0, 255); // Set LED color to blue
  }
  else
  {
    digitalWrite(waterPump, LOW); // Turn off water pump
    setLEDColor(0, 255, 0);       // Set LED color to green
  }
}

void controlGrowLight(int lightValue)
{
  if (lightValue < 50)
  {
    digitalWrite(LED, HIGH); // Turn on grow light
  }
  else
  {
    digitalWrite(LED, LOW); // Turn off grow light
  }
}

void setLEDColor(int red, int green, int blue)
{
  digitalWrite(R_pin, red);   // Set red color intensity
  digitalWrite(G_pin, green); // Set green color intensity
  digitalWrite(B_pin, blue);  // Set blue color intensity
}
