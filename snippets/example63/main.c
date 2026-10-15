// #region demo
#include <stdio.h>

void increment(int n) {
    n = n + 1;  // Changes the COPY of n
    printf("Inside the function: n = %d\n", n);
}

int main(void) {
    int x = 5;
    
    printf("Before: x = %d\n", x);
    increment(x);
    printf("After: x = %d\n", x);  // x has NOT changed!
    
    return 0;
}
// #endregion demo
