#include "wifi.h"
#include "secrets.h"
#include <WiFi.h>

void wifiSetup() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi!");
}

bool wifiIsConnected() {
  return WiFi.status() == WL_CONNECTED;
}
