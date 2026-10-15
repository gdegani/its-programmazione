#include <stdio.h>

int main(void) {
    // #region validation
    float temperature;
    int valid = 0;

    // Keep asking until the reading is in the sensor range
    while (!valid) {
        printf("Enter the temperature (-40 to 150 C): ");

        if (scanf("%f", &temperature) != 1) {
            printf("Error: enter a number\n");
            while (getchar() != '\n');  // Discard the rest of the line
            continue;
        }

        if (temperature < -40 || temperature > 150) {
            printf("Reading out of range\n");
            continue;
        }

        valid = 1;
        printf("Reading accepted: %.1f C\n", temperature);
    }
    // #endregion
    return 0;
}
