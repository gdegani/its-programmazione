#include <stdio.h>

int main(void)
{

    // #region ciclo
    int i, j;
    for (i = 1; i <= 4; i++)
    {
        // Outer loop
        for (j = 1; j <4 ; j++)
        {
            // Inner loop
            printf("%d,%d ", i, j);
        }
        printf("\n");
    }
    printf("%d,%d \n", i, j);

    // #endregion
    return 0;
}
