#include <stdio.h>

int main(void) {
    // #region monitor
    const float WARNING = 80.0f;
    const float ALARM = 100.0f;
    const int SAMPLES = 5;

    float value, min, max;
    float sum = 0;

    for (int i = 1; i <= SAMPLES; i++) {
        printf("Reading %d: ", i);
        scanf("%f", &value);

        if (i == 1 || value < min) {
            min = value;
        }
        if (i == 1 || value > max) {
            max = value;
        }
        sum += value;

        if (value >= ALARM) {
            printf("ALARM: stopping the acquisition\n");
            break;
        } else if (value >= WARNING) {
            printf("Warning: temperature high\n");
        }
    }
    printf("Min: %.1f  Max: %.1f  Sum: %.1f\n", min, max, sum);
    // #endregion
    return 0;
}
