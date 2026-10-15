#include <stdio.h>

int main(void) {
    // #region demo
    // ✅ With arrays - SIMPLE!
    double temp[100];

    // Read the readings
    for (int i = 0; i < 100; i++) {
        printf("Enter reading %d: ", i + 1);
        scanf("%lf", &temp[i]);
    }

    // Compute the average
    double sum = 0;
    for (int i = 0; i < 100; i++) {
        sum += temp[i];
    }
    double average = sum / 100.0;
    // #endregion demo
    return 0;
}
