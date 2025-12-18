/*
 * Example: Debugging case with AI assistance
 * 
 * Original buggy code that was debugged with AI help
 * 
 * AI Prompt used:
 * "This code has bugs. Find and explain all issues:
 *  1. Uninitialized variable
 *  2. Off-by-one error
 *  3. Missing boundary check
 *  Suggest fixes with explanations."
 */

#include <stdio.h>

// ❌ BUGGY VERSION
void buggy_sum_array(int arr[], int size) {
    int sum;  // BUG 1: Uninitialized variable
    
    // BUG 2: Off-by-one error (i <= size instead of i < size)
    for (int i = 0; i <= size; i++) {
        sum += arr[i];  // BUG 3: Accessing arr[size] which is out of bounds
    }
    
    printf("Sum: %d\n", sum);
}

// ✅ FIXED VERSION (with AI assistance)
/**
 * Calculates and prints the sum of array elements.
 * 
 * @param arr Pointer to integer array
 * @param size Number of elements in the array
 * 
 * Fixes applied:
 * - Initialized sum to 0
 * - Changed loop condition from i <= size to i < size
 * - Added NULL check for safety
 */
void fixed_sum_array(const int *arr, int size) {
    if (arr == NULL || size <= 0) {
        printf("Invalid input\n");
        return;
    }
    
    int sum = 0;  // FIX 1: Initialize to 0
    
    // FIX 2: Correct loop boundary (i < size)
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    
    printf("Sum: %d\n", sum);
}

int main(void) {
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;
    
    printf("Testing buggy version:\n");
    // buggy_sum_array(numbers, size);  // Commented out - would crash or show wrong result
    
    printf("Testing fixed version:\n");
    fixed_sum_array(numbers, size);  // Should print: Sum: 15
    
    return 0;
}

/*
 * AI Explanation provided:
 * 
 * Bug 1 - Uninitialized variable:
 * Variable 'sum' is declared but not initialized. In C, local variables
 * contain garbage values until explicitly initialized. This causes 
 * undefined behavior.
 * 
 * Bug 2 - Off-by-one error:
 * The loop condition 'i <= size' causes the loop to iterate size+1 times.
 * For an array of size 5, valid indices are 0-4, but the loop tries to
 * access index 5, which is out of bounds.
 * 
 * Bug 3 - Missing boundary check:
 * No validation that 'arr' is not NULL or that 'size' is positive.
 * This could lead to crashes or undefined behavior with invalid input.
 */
