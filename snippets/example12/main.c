#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    int n, i, j, temp;
    int arr[MAX_SIZE];

    // Request the number of elements (N < 100)
    printf("Enter the number of elements (N < 100): ");
    scanf("%d", &n);

    // Check if N is greater than or equal to 100
    if (n >= 100) {
        printf("Error: N must be less than 100.\n");
        return 1;
    }

    // Request N integer numbers
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in ascending order using bubble sort algorithm
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}