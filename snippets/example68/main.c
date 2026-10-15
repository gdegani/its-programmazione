#include <stdio.h>

// #region functions
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void multiply_by_2(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] *= 2;  // Changes the original array!
    }
}
// #endregion functions

// #region main
int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;

    printf("Original: ");
    print_array(numbers, size);

    multiply_by_2(numbers, size);

    printf("Modified: ");
    print_array(numbers, size);

    return 0;
}
// #endregion main
