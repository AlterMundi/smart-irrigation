#ifndef INFLUXDB_H
#define INFLUXDB_H

void influxSetup();
bool influxSendMeasurement(int moisture);

#endif
