#include <stdio.h>

int main(void) {
    // #region demo
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char line[100];
    while (fgets(line, 100, file) != NULL) {
        printf("%s", line);  // line already contains \n
    }

    fclose(file);
    // #endregion demo
    return 0;
}
