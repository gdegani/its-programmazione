#include <stdio.h>

int main(void) {
    // #region demo
    // Count by 2
    for (int i = 0; i < 10; i += 2) {
        printf("%d ", i);  // Output: 0 2 4 6 8
    }

    // Count backwards
    for (int i = 10; i > 0; i--) {
        printf("%d ", i);  // Output: 10 9 8 7 6 5 4 3 2 1
    }
    // #endregion demo
    return 0;
}
