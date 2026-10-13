#include <stdio.h>

#include "sensor.h"

int main(void) {
    int raw = 3200;
    double celsius = adc_to_celsius(raw);

    printf("Raw: %d, temperature: %.1f C\n", raw, celsius);
    if (is_over_threshold(celsius, 75.0)) {
        printf("ALARM: temperature above 75 C\n");
    }
    return 0;
}
