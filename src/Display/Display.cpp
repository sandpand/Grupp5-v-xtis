#include "Display/Display.h"

/**
 * @class Display
 * @brief Handles the LCD display for showing sensor values.
 *
 * This class is responsible for initializing and updating the LCD display
 * with the soil moisture and light sensor values.
 */

/**
 * @brief Constructor for the Display class.
 *
 * @param rs Register select pin for the LCD.
 * @param en Enable pin for the LCD.
 * @param d4 Data pin 4 for the LCD.
 * @param d5 Data pin 5 for the LCD.
 * @param d6 Data pin 6 for the LCD.
 * @param d7 Data pin 7 for the LCD.
 */
Display::Display(int rs, int en, int d4, int d5, int d6, int d7)
    : lcd(rs, en, d4, d5, d6, d7) {}

/**
 * @brief Initializes the LCD display.
 *
 * This method sets up the LCD display with a 16x2 character configuration.
 */
void Display::begin()
{
    lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows.
}

/**
 * @brief Updates the LCD display with sensor values.
 *
 * This method displays the soil moisture and light sensor values on the LCD.
 *
 * @param soilValue The current soil moisture value.
 * @param lightValue The current light intensity value.
 */
void Display::showValues(int soilValue, int lightValue)
{
    // Display soil moisture value on the first row.
    lcd.setCursor(0, 0);       // Set cursor to the beginning of the first row.
    lcd.print("Soil value: "); // Print label for soil value.
    lcd.print("    ");         // Clear any previous value.
    lcd.setCursor(12, 0);      // Move cursor to the position for the value.
    lcd.print(soilValue);      // Print the soil moisture value.

    // Display light intensity value on the second row.
    lcd.setCursor(0, 1);        // Set cursor to the beginning of the second row.
    lcd.print("Light value: "); // Print label for light value.
    lcd.print("    ");          // Clear any previous value.
    lcd.setCursor(13, 1);       // Move cursor to the position for the value.
    lcd.print(lightValue);      // Print the light intensity value.
}