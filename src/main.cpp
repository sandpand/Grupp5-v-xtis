#include <LiquidCrystal.h>
#include <Arduino.h>

void displaySensorValues(int soilValue, int lightValue);
void controlWaterPumpAndLEDs(int soilValue);
void controlGrowLight(int lightValue);
void setLEDColor(int red, int green, int blue);

int LED = 5;
int R_pin = 2;
int G_pin = 3;
int B_pin = 4;

int waterPump = 12;
int soilSensor = A0;
int lightSensor = A1;

int soilVal;
int lightVal;

LiquidCrystal lcd_1(6, 7, 8, 9, 10, 11);

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

void loop()
{
  soilVal = analogRead(soilSensor);
  lightVal = analogRead(lightSensor);
  displaySensorValues(soilVal, lightVal);
  controlWaterPumpAndLEDs(soilVal);

  controlGrowLight(lightVal);

  delay(1000);
}

void displaySensorValues(int soilValue, int lightValue)
{
  lcd_1.setCursor(0, 0);
  lcd_1.print("Soil value: ");
  lcd_1.print("    ");  
  lcd_1.setCursor(12, 0);
  lcd_1.print(soilValue);

  Serial.print("Soil value: ");
  Serial.println(soilValue);

  lcd_1.setCursor(0, 1);
  lcd_1.print("Light value: ");
  lcd_1.print("    ");  
  lcd_1.setCursor(13, 1);
  lcd_1.print(lightValue);

  Serial.print("Light value: ");
  Serial.println(lightValue);
}


void controlWaterPumpAndLEDs(int soilValue)
{
  if (soilValue > 950)
  {
    Serial.println("Water pump on");

    digitalWrite(waterPump, HIGH);
    setLEDColor(255, 0, 0);
    delay(1000);
  }
  else if (soilValue >= 365)
  {
    setLEDColor(0, 0, 255);
  }
  else
  {
    digitalWrite(waterPump, LOW);
    setLEDColor(0, 255, 0);
  }
}

void controlGrowLight(int lightValue)
{
  if (lightValue < 50)
  {
    digitalWrite(LED, HIGH);
    //Serial.println("Grow light on");
  }
  else
  {
    digitalWrite(LED, LOW);
  }
}

void setLEDColor(int red, int green, int blue)
{
  digitalWrite(R_pin, red);
  digitalWrite(G_pin, green);
  digitalWrite(B_pin, blue);
}
