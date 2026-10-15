#include <stdio.h>

int main(void) {
    FILE *file = stdin;
    // #region demo
    char line[100];
    long timestamp;
    int sensor_id;
    double value;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (sscanf(line, "%ld;%d;%lf", &timestamp, &sensor_id, &value) == 3) {
            // valid row: all three fields were read
        }
    }
    // #endregion demo
    return 0;
}
