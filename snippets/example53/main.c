#include <stdio.h>

int main(void) {
    // #region demo
    float temp = 92.5f;

    if (temp >= 100.0f) {
        printf("ALARM\n");
    } else if (temp >= 80.0f) {
        printf("Warning\n");
    } else {
        printf("Normal\n");
    }
    // Output: Warning
    // #endregion demo
    return 0;
}
