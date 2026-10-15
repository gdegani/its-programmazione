#include <stdio.h>

int main(void) {
    // #region demo
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int T[3][2];  // Transpose: rows and columns swapped

    for (int r = 0; r < 2; r++) {
        for (int c = 0; c < 3; c++) {
            T[c][r] = A[r][c];
        }
    }
    // T = {{1, 4}, {2, 5}, {3, 6}}
    // #endregion demo
    return 0;
}
