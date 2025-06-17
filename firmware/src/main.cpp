#include <Arduino.h>
#include "sensor.h"
#include "wifi.h"
#include "influxdb.h"

void setup() {
  Serial.begin(115200);
  wifiSetup();
  sensorSetup();
  influxSetup();
}

void loop() {
  if (wifiIsConnected()) {
    int moisture = readSoilMoisturePercent();
    Serial.print("Soil moisture (%): ");
    Serial.println(moisture);

    if (influxSendMeasurement(moisture)) {
      Serial.println("Sent to InfluxDB");
    } else {
      Serial.println("Failed to send data");
    }
  } else {
    Serial.println("WiFi disconnected, retrying...");
    wifiSetup();
  }

  delay(5000);
}
