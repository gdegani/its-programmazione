#include <stdio.h>

#define MAX 100

int main() {
    int values[MAX];
    int n;

    // Ask how many values will be entered
    printf("How many values do you want to enter (max 100)? ");
    scanf("%d", &n);

    if (n > MAX) {
        printf("The maximum number of values is 100.\n");
        return 1;
    }

    // Ask for the values
    printf("Enter %d values:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    // Display even values in insertion order
    printf("Even values: ");
    for (int i = 0; i < n; i++) {
        if (values[i] % 2 == 0) {
            printf("%d ", values[i]);
        }
    }

    // Display odd values in reverse order
    printf("\nOdd values: ");
    for (int i = n - 1; i >= 0; i--) {
        if (values[i] % 2 != 0) {
            printf("%d ", values[i]);
        }
    }
    printf("\n");

    return 0;
}
