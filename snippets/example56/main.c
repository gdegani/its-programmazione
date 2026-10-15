#include <stdio.h>

int main(void) {
    // #region demo
    int arr[5] = {1, 2, 3, 4, 5};
    int temp;

    for (int i = 0; i < 5/2; i++) {
        temp = arr[i];
        arr[i] = arr[4 - i];
        arr[4 - i] = temp;
    }
    // Result: {5, 4, 3, 2, 1}
    // #endregion demo
    return 0;
}
