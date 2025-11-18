/*
 * Example: Variable declarations and basic data types
 * Expected function: int main(void);
 * Learning objective: demonstrate declaration, initialization, and sizeof operator
 */

#include <stdio.h>

int main(void) {
    // Integer types
    int age = 25;
    short height_cm = 175;
    long population = 7800000000L;
    unsigned int count = 100;
    
    // Floating point types
    float temperature = 20.5f;
    double pi = 3.14159265358979;
    
    // Character type
    char grade = 'A';
    char initial = 'G';
    
    // Display values
    printf("=== Variable Values ===\n");
    printf("Age: %d years\n", age);
    printf("Height: %d cm\n", height_cm);
    printf("Population: %ld\n", population);
    printf("Count: %u\n", count);
    printf("Temperature: %.1f°C\n", temperature);
    printf("Pi: %.10f\n", pi);
    printf("Grade: %c\n", grade);
    printf("Initial: %c\n\n", initial);
    
    // Display sizes
    printf("=== Type Sizes (bytes) ===\n");
    printf("sizeof(char):   %zu\n", sizeof(char));
    printf("sizeof(short):  %zu\n", sizeof(short));
    printf("sizeof(int):    %zu\n", sizeof(int));
    printf("sizeof(long):   %zu\n", sizeof(long));
    printf("sizeof(float):  %zu\n", sizeof(float));
    printf("sizeof(double): %zu\n", sizeof(double));
    
    return 0;
}
