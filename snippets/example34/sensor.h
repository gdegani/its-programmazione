#ifndef SENSOR_H
#define SENSOR_H

// 12-bit ADC reading -> degrees Celsius
double adc_to_celsius(int raw);

// 1 if value is above limit, else 0
int is_over_threshold(double value, double limit);

#endif
