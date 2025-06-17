# 🌱 Smart Irrigation System (ESP32 + InfluxDB + Grafana)

Este proyecto implementa un sistema de riego inteligente utilizando un ESP32, sensores de humedad de suelo, y una electroválvula, con visualización de métricas en Grafana a través de InfluxDB.

---

## 📦 Estructura

smart-irrigation/
├── firmware/ # Código del ESP32
│ ├── src/
│ │ ├── main.cpp
│ │ ├── sensor.cpp/h
│ │ ├── wifi.cpp/h
│ │ ├── influxdb.cpp/h
│ │ ├── secrets.cpp (NO COMMITEAR - está en .gitignore)
│ │ └── secrets.example.cpp/h
│ └── platformio.ini
├── docker-compose.yml # Grafana + InfluxDB
└── README.md

---

## 🚀 Requisitos

- ESP32 (dev board)
- Sensor de humedad (analógico)
- Electroválvula 12V + relé
- Docker + Docker Compose
- PlatformIO (VS Code recomendado)

---

## 🐳 Docker (InfluxDB + Grafana)

1. Crear archivo `.env` en el root:

```env
GF_USER=admin
GF_PASS=admin123
```

2. Levantar los contenedores:
```sh
docker-compose up -d
```
* InfluxDB: http://localhost:8086
* Grafana: http://localhost:3000

⚠️ Usuario por defecto en Grafana: los definidos en .env.

## Firmware ESP32
1. Clonar este repositorio
2. Renombrar ```secrets.example.cpp/h``` a ```secrets.cpp/h``` y completar:

```cpp
// secrets.h
extern const char* WIFI_SSID;
extern const char* WIFI_PASSWORD;
extern const char* INFLUX_HOST;
extern const char* INFLUX_DB;
extern const char* INFLUX_USER;
extern const char* INFLUX_PASS;
extern const int   INFLUX_PORT;
```

```cpp
// secrets.cpp
#include "secrets.h"

const char* WIFI_SSID = "TuSSID";
const char* WIFI_PASSWORD = "TuPassword";

const char* INFLUX_HOST = "192.168.x.x";  // IP del host donde corre InfluxDB
const char* INFLUX_DB = "smart_irrigation";
const char* INFLUX_USER = "admin";
const char* INFLUX_PASS = "admin123";
const int INFLUX_PORT = 8086;

```

## 📈 Grafana Dashboard

1. Crear una fuente de datos InfluxDB:

* URL:```http://influxdb:8086```
* Database: ```smart_irrigation```
* User/Pass: mismos que ```secrets.cpp```
* Query Lenguaje: InfluxQL
* HTTP Method: ```POST```

2. Query ejemplo:

```sql
SELECT mean("value") 
FROM "soil_moisture" 
WHERE $timeFilter 
GROUP BY time($__interval) fill(null)
```

