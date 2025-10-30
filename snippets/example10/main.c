#include <stdio.h>

void increment(int *value) {
    (*value)++;
}

int main() {
    int number = 10;
    
    printf("Before: number = %d\n", number);
    increment(&number);
    printf("After: number = %d\n", number);

    return 0;
}
