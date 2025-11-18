/*
 * Example: Relational and logical operators
 * Expected function: int main(void);
 * Learning objective: demonstrate comparison and boolean logic operations
 */

#include <stdio.h>

int main(void) {
    int a = 10, b = 20, c = 10;
    
    printf("=== Relational Operators ===\n");
    printf("a = %d, b = %d, c = %d\n\n", a, b, c);
    
    printf("a == b: %d (false)\n", a == b);
    printf("a == c: %d (true)\n", a == c);
    printf("a != b: %d (true)\n", a != b);
    printf("a < b:  %d (true)\n", a < b);
    printf("a > b:  %d (false)\n", a > b);
    printf("a <= c: %d (true)\n", a <= c);
    printf("b >= a: %d (true)\n\n", b >= a);
    
    printf("=== Logical Operators ===\n");
    int x = 1, y = 0;  // 1 = true, 0 = false
    printf("x = %d (true), y = %d (false)\n\n", x, y);
    
    printf("x && y:  %d (AND: both must be true)\n", x && y);
    printf("x || y:  %d (OR: at least one must be true)\n", x || y);
    printf("!x:      %d (NOT: inverts the value)\n", !x);
    printf("!y:      %d\n\n", !y);
    
    printf("=== Combined Conditions ===\n");
    int age = 25;
    int has_license = 1;
    
    printf("age = %d, has_license = %d\n\n", age, has_license);
    
    int can_drive = (age >= 18) && has_license;
    printf("Can drive (age >= 18 AND has_license): %d\n\n", can_drive);
    
    printf("=== Short-circuit Evaluation ===\n");
    int num = 0;
    printf("num = %d\n", num);
    
    // This is safe because if num == 0, the division is not executed
    if (num != 0 && 100 / num > 5) {
        printf("Division executed\n");
    } else {
        printf("Division skipped (avoided division by zero!)\n");
    }
    
    return 0;
}
