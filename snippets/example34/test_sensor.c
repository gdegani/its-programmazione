#include <assert.h>
#include <stdio.h>

#include "sensor.h"

static int near(double a, double b) {
    return a - b < 1e-6 && b - a < 1e-6;
}

int main(void) {
    // adc_to_celsius: known values
    assert(near(adc_to_celsius(0), 0.0));
    assert(near(adc_to_celsius(4095), 100.0));

    // is_over_threshold: below, above and exactly on the threshold
    assert(is_over_threshold(80.0, 75.0));
    assert(!is_over_threshold(70.0, 75.0));
    assert(!is_over_threshold(75.0, 75.0));

    printf("All tests passed\n");
    return 0;
}
