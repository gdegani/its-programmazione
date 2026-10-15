// #region demo
#include <stdio.h>

void function_a(void) {
    int x = 10;  // x local to function_a
    printf("function_a: x = %d\n", x);
}

void function_b(void) {
    int x = 20;  // x local to function_b (different from the x of function_a)
    printf("function_b: x = %d\n", x);
}

int main(void) {
    int x = 5;   // x local to main
    
    printf("main: x = %d\n", x);
    function_a();
    function_b();
    printf("main: x = %d\n", x);  // the x of main has not changed
    
    return 0;
}
// #endregion demo
