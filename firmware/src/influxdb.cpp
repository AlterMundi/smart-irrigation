#include "secrets.h"
#include <WiFi.h>
#include <HTTPClient.h>

void influxSetup() {
  // Placeholder, por ahora no hace nada
}

bool influxSendMeasurement(int moisture) {
  if (WiFi.status() != WL_CONNECTED) return false;

  HTTPClient http;
  String url = String("http://") + INFLUX_HOST + ":" + String(INFLUX_PORT) + "/write?db=" + INFLUX_DB;
  
  if (!http.begin(url)) {
    return false;
  }

  if (strlen(INFLUX_USER) > 0) {
    http.setAuthorization(INFLUX_USER, INFLUX_PASS);
  }

  String payload = "soil_moisture,sensor=oil_sensor value=" + String(moisture);
  int httpCode = http.POST(payload);
  http.end();

  return (httpCode == 204);
}
