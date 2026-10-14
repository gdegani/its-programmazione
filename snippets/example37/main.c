#include <stdio.h>

int main(void) {
    // #region snippet1
    int first, second;
    float average;

    printf("Enter first temperature: ");
    scanf("%d", &first);

    printf("Enter second temperature: ");
    scanf("%d", &second);

    average = (float)(first + second) / 2;
    printf("Average: %.2f\n", average);
    // #endregion snippet1

    // #region snippet2
    int day, month, year;

    printf("Enter date (dd/mm/yyyy): ");
    scanf("%d/%d/%d", &day, &month, &year);
    printf("Day %d, month %d, year %d\n", day, month, year);
    // #endregion snippet2
    return 0;
}
