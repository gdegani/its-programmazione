#include <stdio.h>

int main(void) {
    // #region demo
    FILE *file = fopen("table.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "%-10s %-5s\n", "Name", "Grade");
    fprintf(file, "%-10s %-5d\n", "Marco", 28);
    fprintf(file, "%-10s %-5d\n", "Anna", 30);

    fclose(file);
    // #endregion demo
    return 0;
}
