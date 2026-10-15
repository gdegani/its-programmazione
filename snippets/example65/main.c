// #region demo
#include <stdio.h>

int square(int n) {
    return n * n;
}

int main(void) {
    int x = 5;
    int result = square(x);  // Function call
    
    printf("The square of %d is %d\n", x, result);
    // Output: The square of 5 is 25
    
    // Direct call inside printf
    printf("The square of 7 is %d\n", square(7));
    // Output: The square of 7 is 49
    
    return 0;
}
// #endregion demo
