/*
 * Example: Basic input and output with printf() and scanf()
 * Expected function: int main(void);
 * Learning objective: demonstrate formatted I/O operations
 */

#include <stdio.h>

int main(void) {
    int age;
    float height;
    char grade;
    
    printf("=== Basic Input/Output Example ===\n\n");
    
    // Reading integer
    printf("Enter your age: ");
    scanf("%d", &age);
    
    // Reading float
    printf("Enter your height (in meters): ");
    scanf("%f", &height);
    
    // Reading character (space before %c to skip whitespace)
    printf("Enter your grade (A-F): ");
    scanf(" %c", &grade);
    
    // Output with formatting
    printf("\n=== Your Information ===\n");
    printf("Age: %d years\n", age);
    printf("Height: %.2f m\n", height);
    printf("Grade: %c\n\n", grade);
    
    // Formatted output examples
    printf("=== Formatted Output ===\n");
    float pi = 3.14159265;
    printf("Pi with 2 decimals: %.2f\n", pi);
    printf("Pi with 4 decimals: %.4f\n", pi);
    printf("Pi in 10 character field: %10.2f\n", pi);
    printf("Pi left-aligned: %-10.2f|\n\n", pi);
    
    // Multiple input on same line
    int num1, num2, num3;
    printf("Enter three numbers separated by spaces: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    
    int sum = num1 + num2 + num3;
    float average = (float)sum / 3;
    
    printf("\nNumbers entered: %d, %d, %d\n", num1, num2, num3);
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);
    
    return 0;
}
