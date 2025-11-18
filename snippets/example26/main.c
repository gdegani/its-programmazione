/*
 * Example: Arithmetic operators and type conversions
 * Expected function: int main(void);
 * Learning objective: demonstrate arithmetic operations, operator precedence, and casting
 */

#include <stdio.h>

int main(void) {
    int a = 10, b = 3;
    float x = 10.0f, y = 3.0f;
    
    printf("=== Integer Arithmetic ===\n");
    printf("a = %d, b = %d\n", a, b);
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d  (integer division!)\n", a / b);
    printf("a %% b = %d  (modulo/remainder)\n\n", a % b);
    
    printf("=== Float Arithmetic ===\n");
    printf("x = %.1f, y = %.1f\n", x, y);
    printf("x + y = %.1f\n", x + y);
    printf("x - y = %.1f\n", x - y);
    printf("x * y = %.1f\n", x * y);
    printf("x / y = %.4f\n\n", x / y);
    
    printf("=== Type Conversion ===\n");
    printf("(float)a / b = %.4f  (cast a to float)\n", (float)a / b);
    printf("a / (float)b = %.4f  (cast b to float)\n", a / (float)b);
    printf("(float)(a / b) = %.4f  (division first, then cast)\n\n", (float)(a / b));
    
    printf("=== Operator Precedence ===\n");
    int result1 = 2 + 3 * 4;
    int result2 = (2 + 3) * 4;
    printf("2 + 3 * 4 = %d\n", result1);
    printf("(2 + 3) * 4 = %d\n\n", result2);
    
    printf("=== Compound Assignment ===\n");
    int num = 10;
    printf("Initial value: %d\n", num);
    num += 5;
    printf("After += 5: %d\n", num);
    num *= 2;
    printf("After *= 2: %d\n", num);
    num -= 10;
    printf("After -= 10: %d\n", num);
    num /= 2;
    printf("After /= 2: %d\n\n", num);
    
    printf("=== Increment/Decrement ===\n");
    int counter = 5;
    int temp;
    printf("counter = %d\n", counter);
    temp = counter++;
    printf("counter++ = %d (post-increment, then counter = %d)\n", temp, counter);
    printf("++counter = %d (pre-increment)\n", ++counter);
    temp = counter--;
    printf("counter-- = %d (post-decrement, then counter = %d)\n", temp, counter);
    printf("--counter = %d (pre-decrement)\n", --counter);
    
    return 0;
}
