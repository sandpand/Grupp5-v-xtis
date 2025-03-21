#include <Arduino.h>
#include "Controller/SmartGardenController.h"

SmartGardenController garden(A0, A1, 11, 2, 3, 4, 5, 16, 6, 7, 8, 9, 10, 12);

void setup()
{
  garden.begin();
}

void loop()
{
  garden.update();
  delay(1000);
}