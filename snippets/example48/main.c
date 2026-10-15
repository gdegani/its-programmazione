#include <stdio.h>

int main(void) {
    // #region demo
    // Solution 1: correct condition
    for (int i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    // Output: 1 2 3 4 5 6 7 8 9 10  ✅

    // Solution 2: offset
    for (int i = 0; i < 10; i++) {
        printf("%d ", i + 1);
    }
    // Output: 1 2 3 4 5 6 7 8 9 10  ✅
    // #endregion demo
    return 0;
}
