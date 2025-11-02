#include <stdio.h>

int main() {
    int array[5] = {10, 20, 30, 40, 50};

    // Print elements and addresses
    for (int i = 0; i < 5; i++) {
        printf("array[%d] = %d at address %p\n", i, array[i], (void*)&array[i]);
    }

    // Pointer arithmetic demonstration
    int *ptr = array;
    printf("\nPointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d at address %p\n", i, *(ptr + i), (void*)(ptr + i));
    }

    return 0;
}
