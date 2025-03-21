#include <LiquidCrystal.h>
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 5
#define LED_COUNT 16
#define WATER_PUMP_PIN 11
#define SOIL_SENSOR_PIN A0
#define LIGHT_SENSOR_PIN A1
#define R_PIN 2
#define G_PIN 3
#define B_PIN 4

class SoilSensor {
public:
    int read() {
        return analogRead(SOIL_SENSOR_PIN);
    }
};

class LightSensor {
public:
    int read() {
        return analogRead(LIGHT_SENSOR_PIN);
    }
};

class WaterPump {
public:
    void turnOn() {
        digitalWrite(WATER_PUMP_PIN, HIGH);
    }
    void turnOff() {
      digitalWrite(WATER_PUMP_PIN, LOW);
  }
};

class LEDController {
private:
    Adafruit_NeoPixel strip;
public:
    LEDController() : strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800) {}
    
    void begin() {
        strip.begin();
        strip.setBrightness(50);
        strip.show();
    }
    
    void setNeopixelColor(int red, int green, int blue) {
        for (int i = 0; i < LED_COUNT; i++) {
            strip.setPixelColor(i, strip.Color(red, green, blue));
        }
        strip.show();
    }
    
    void setRGBColor(int red, int green, int blue) {
        analogWrite(R_PIN, red);
        analogWrite(G_PIN, green);
        analogWrite(B_PIN, blue);
    }
};

class Display {
private:
    LiquidCrystal lcd;
public:
    Display() : lcd(6, 7, 8, 9, 10, 12) {}
    
    void begin() {
        lcd.begin(16, 2);
    }
    
    void showValues(int soilValue, int lightValue) {
        lcd.setCursor(0, 0);
        lcd.print("Soil: ");
        lcd.print(soilValue);
        lcd.setCursor(0, 1);
        lcd.print("Light: ");
        lcd.print(lightValue);
    }
};

class SmartGardenController {
private:
    SoilSensor soilSensor;
    LightSensor lightSensor;
    WaterPump waterPump;
    LEDController ledController;
    Display display;

public:
    void begin() {
        pinMode(SOIL_SENSOR_PIN, INPUT);
        pinMode(LIGHT_SENSOR_PIN, INPUT);
        pinMode(WATER_PUMP_PIN, OUTPUT);
        pinMode(R_PIN, OUTPUT);
        pinMode(G_PIN, OUTPUT);
        pinMode(B_PIN, OUTPUT);
        ledController.begin();
        display.begin();
        Serial.begin(9600);
    }

    void update() {
        int soilVal = soilSensor.read();
        int lightVal = lightSensor.read();
        
        display.showValues(soilVal, lightVal);
        Serial.print("Soil: "); Serial.println(soilVal);
        Serial.print("Light: "); Serial.println(lightVal);
        
        controlWaterPumpAndLEDs(soilVal);
        controlGrowLight(lightVal);
    }

    void controlWaterPumpAndLEDs(int soilValue) {
        if (soilValue > 950) {
            waterPump.turnOn();
            ledController.setRGBColor(0, 0, 255);
        } else if (soilValue >= 450) {
            ledController.setRGBColor(255, 0, 0);
        } else {
            waterPump.turnOff();
            ledController.setRGBColor(0, 255, 0);
        }
    }

    void controlGrowLight(int lightValue) {
        if (lightValue < 20) {
            Serial.println("Grow light ON");
            ledController.setNeopixelColor(255, 165, 0);
        } else {
            Serial.println("Grow light OFF");
            ledController.setNeopixelColor(0, 0, 0);
        }
    }
};

SmartGardenController garden;

void setup() {
    garden.begin();
}

void loop() {
    garden.update();
    delay(1000);
}
