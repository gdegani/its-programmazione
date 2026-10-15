// #region demo
#include <stdio.h>

void increment(int *n) {
    *n = *n + 1;  // Changes the pointed value
}

int main(void) {
    int x = 5;
    
    printf("Before: x = %d\n", x);
    increment(&x);  // Passes the address of x
    printf("After: x = %d\n", x);  // x has changed!
    
    return 0;
}
// #endregion demo
