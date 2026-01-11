#include <stdio.h>

int example_while2(void) {

    // #region ciclo
    int v;
    int sum = 0;
    scanf("%d", &v);
    while (v != 0) {
        sum += v;
        scanf("%d", &v);
    }
    printf("Sum: %d", sum);
    // #endregion
    return 0;
}
