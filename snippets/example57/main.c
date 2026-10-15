#include <stdio.h>

int main(void) {
    // #region demo
    int numbers[5] = {3, 7, 2, 9, 4};
    int max = numbers[0];  // Assume the first is max

    for (int i = 1; i < 5; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }
    printf("Maximum: %d\n", max);  // Output: 9
    // #endregion demo
    return 0;
}
