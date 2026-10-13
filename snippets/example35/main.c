#include <stdint.h>
#include <stdio.h>

// #region snippet1
// Written by an interrupt handler, read by the main loop:
// without volatile the compiler may read it only once
volatile uint8_t sensor_ready = 0;

void sensor_interrupt(void) {
    sensor_ready = 1;
}
// #endregion snippet1

int main(void) {
    // On a real microcontroller the hardware calls sensor_interrupt();
    // here we simply call it ourselves.
    sensor_interrupt();

    while (!sensor_ready) {
        // wait for the sensor
    }
    printf("Sensor ready\n");
    return 0;
}
