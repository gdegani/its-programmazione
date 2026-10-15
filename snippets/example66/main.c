// #region demo
#include <stdio.h>

// Declarations (prototypes) at the top
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);

int main(void) {
    printf("5 + 3 = %d\n", add(5, 3));
    printf("5 - 3 = %d\n", subtract(5, 3));
    printf("5 * 3 = %d\n", multiply(5, 3));
    return 0;
}

// Definitions after main
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}
// #endregion demo
