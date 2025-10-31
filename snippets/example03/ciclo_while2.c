#include <stdio.h>

int example_while2(void) {

    // #region ciclo
    int v;
    int somma = 0;
    scanf("%d", &v);
    while (v != 0) {
        somma += v;
        scanf("%d", &v);
    }
    printf("Somma: %d", somma);
    // #endregion
    return 0;
}
