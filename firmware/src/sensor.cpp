#include "sensor.h"
#include <Arduino.h>

const int sensorPin = 34;  // ADC1_CH6

const int adc_min = 1000;  // calibrate saturated soil (max)
const int adc_max = 2500;  // calibrate dry soil (min)

void sensorSetup() {
  analogReadResolution(12);
  Serial.begin(115200);
}

int readSoilMoisturePercent() {
  int adc_val = analogRead(sensorPin);
  int moisture_pct = (adc_max - adc_val) * 100 / (adc_max - adc_min);
  if (moisture_pct < 0) moisture_pct = 0;
  if (moisture_pct > 100) moisture_pct = 100;
  return moisture_pct;
}
