#include <stdio.h>

int main(void) {
    // #region snippet1
    int x = 5, y = 2;
    float a, b;

    a = x / y;                // 2.0 (integer division, then conversion)
    b = (float)x / y;         // 2.5
    b = (float)x / (float)y;  // 2.5

    int z = 3.9;              // 3 (decimal part dropped, the compiler warns)
    int w = (int)3.9;         // 3 (explicit cast, no warning)

    double d = 5 + 2.5;       // 7.5 (5 is promoted to 5.0)
    // #endregion snippet1

    printf("a=%.1f b=%.1f z=%d w=%d d=%.1f\n", a, b, z, w, d);
    return 0;
}
