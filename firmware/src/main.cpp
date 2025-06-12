#include <Arduino.h>
#include "sensor.h"

void setup() {
  Serial.begin(115200);
  sensorSetup();
}

void loop() {
  int moisture = readSoilMoisturePercent();
  Serial.print("Soil Moisture (%): ");
  Serial.println(moisture);
  delay(1000);
}
