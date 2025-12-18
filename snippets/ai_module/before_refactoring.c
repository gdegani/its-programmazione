/*
 * Example: Code before AI-assisted refactoring
 * This code works but has poor readability and naming
 */

#include <stdio.h>

// Poor naming and unclear logic
int f(int a, int b) {
    if(b==0) return a;
    return a%b==0?a/b:a;
}

// No input validation, poor naming
void p(int x[], int n) {
    int i;
    for(i=0;i<n;i++)printf("%d ",x[i]);
    printf("\n");
}

// Global state - bad practice
int c = 0;

void inc() {
    c++;
}

int get() {
    return c;
}

int main(void) {
    int nums[] = {10, 20, 30, 40, 50};
    
    p(nums, 5);
    
    int result = f(20, 4);
    printf("Result: %d\n", result);
    
    inc();
    inc();
    printf("Counter: %d\n", get());
    
    return 0;
}
