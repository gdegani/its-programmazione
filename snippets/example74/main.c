#include <stdio.h>

int main(void) {
    // #region demo
    FILE *file = fopen("numbers.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int number;
    while (fscanf(file, "%d", &number) == 1) {
        printf("Read: %d\n", number);
    }

    fclose(file);
    // #endregion demo
    return 0;
}
