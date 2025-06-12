# smart-irrigation

## Platformio.ini config

```sh
platformio run --target upload
platformio device monitor

```
# Humidity Sensor

The formula converts the raw ADC reading from the capacitive soil moisture sensor into a percentage representing soil moisture level between 0% (completely dry) and 100% (fully saturated). It uses calibrated minimum and maximum ADC values corresponding to saturated and dry soil conditions.

```sh
moisture_percentage = ((adc_max - adc_value) / (adc_max - adc_min)) * 100
```

```adc_value``` is the current raw ADC reading
```adc_min``` is the ADC reading for fully saturated soil
```adc_max``` is the ADC reading for completely dry soil

The result is clamped between 0% and 100%. This linear mapping translates sensor readings into a normalized moisture percentage for easy interpretation and control logic. Calibration of adc_min and adc_max is required per sensor and environment.

### Result 

[![sensor.png](https://i.postimg.cc/d1Qy1qyY/sensor.png)](https://postimg.cc/ns5zSf2R)