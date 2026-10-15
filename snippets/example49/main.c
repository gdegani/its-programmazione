#include <stdio.h>

int main(void) {
    // #region demo
    for (int row = 1; row <= 5; row++) {
        for (int col = 1; col <= row; col++) {
            printf("* ");
        }
        printf("\n");
    }
    // Output:
    // *
    // * *
    // * * *
    // * * * *
    // * * * * *
    // #endregion demo
    return 0;
}
