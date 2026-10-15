#include <stdio.h>

int main(void) {
    // #region nested
    // Simulated readings: 3 sensors, 4 samples each
    for (int sensor = 1; sensor <= 3; sensor++) {
        float sum = 0;

        printf("Sensor %d:", sensor);
        for (int sample = 1; sample <= 4; sample++) {
            float value = 20.0f + sensor * 5 + sample * 0.5f;
            printf(" %.1f", value);
            sum += value;
        }
        printf("  | average %.2f\n", sum / 4);
    }
    // #endregion
    return 0;
}
