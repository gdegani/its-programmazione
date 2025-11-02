/*
 * Exercise:
 * Write a program that calculates the square root x of a number n.
 * - Use the bisection algorithm to solve the equation x² = n
 * - Do not use the sqrt library function
 * - Calculate the solution with precision of 0.000001
 * - The input number must be greater than 1.
 * - Otherwise, print an error message and terminate the program.
 */

#include <stdio.h>

int main() {
    double n, x, a, b;
    const double precision = 0.000001;

    // User input
    printf("Enter a number greater than 1: ");
    scanf("%lf", &n);

    // Check if number is valid
    if (n <= 1) {
        printf("Error: number must be greater than 1.\n");
        return 1; // Terminate program with error
    }

    // Initialize limits for bisection method
    a = 1.0;
    b = n;

    do {
        x = (a + b) / 2.0;  // Calculate midpoint
        printf("Midpoint: %.7lf\n", x);

        if (x * x > n)
            b = x;  // If x² is greater than n, update upper limit
        else
            a = x;  // Otherwise, update lower limit
    } while ((b - a) > precision);

    // Print result
    printf("The approximate square root of %.1lf is: %.7lf\n", n, x);

    return 0;
}
