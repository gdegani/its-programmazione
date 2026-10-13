#include "sensor.h"

double adc_to_celsius(int raw) {
    return raw * 100.0 / 4095.0;
}

int is_over_threshold(double value, double limit) {
    return value > limit;
}
