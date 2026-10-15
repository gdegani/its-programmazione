#include <stdio.h>

int main(void) {
    // #region demo
    int count = 0;
    for (int i = 1; i <= 100; i++) {
        printf("%d ", i);
        count++;
        if (count == 10) {
            printf("\n");  // New line after 10 numbers
            break;  // Leave the loop
        }
    }
    // #endregion demo
    return 0;
}
