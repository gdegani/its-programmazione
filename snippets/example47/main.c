#include <stdio.h>

int main(void) {
    // #region demo
    // 1. ✅ sum is not initialized
    int n = 10;
    int sum = 0;  // ✅ Initialize to 0
    for (int i = 1; i <= n; i++) {
        sum = sum + i;
    }

    // 2. ✅ Off-by-one error: i goes from 0 to 10 (11 values instead of 10)
    for (int i = 1; i <= 10; i++) {  // ✅ Start from 1 instead of 0
        printf("%d ", i);
    }
    // Or:
    for (int i = 0; i < 10; i++) {  // ✅ Use < instead of <=
        printf("%d ", i + 1);
    }

    // 3. ✅ Infinite loop: count increases instead of decreasing
    int count = 10;
    while (count > 0) {
        printf("%d ", count);
        count = count - 1;  // ✅ Decrement with -1
    }
    // #endregion demo
    return 0;
}
