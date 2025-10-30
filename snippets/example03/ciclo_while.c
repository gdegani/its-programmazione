#include <stdio.h>

int example_while(void) {

    // #region ciclo

    int i = 0;
    while (i <= 1000) {
        printf("%d ", i);
        i++;
    }
    // #endregion
    return 0;
}
