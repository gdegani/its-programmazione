/*
 * Example: Code after AI-assisted refactoring
 * Improved readability, naming, and removed global state
 * 
 * AI Prompt used:
 * "Refactor this code to improve naming, remove global state,
 *  add input validation, and improve readability.
 *  Keep the same functionality. Add Doxygen comments."
 */

#include <stdio.h>
#include <stddef.h>

/**
 * Performs safe division with modulo check.
 * 
 * @param dividend The numerator
 * @param divisor The denominator
 * @return If divisor is 0, returns dividend.
 *         If divisor divides dividend evenly, returns the quotient.
 *         Otherwise returns dividend.
 */
int safe_division_with_check(int dividend, int divisor) {
    if (divisor == 0) {
        return dividend;  // Avoid division by zero
    }
    
    if (dividend % divisor == 0) {
        return dividend / divisor;
    }
    
    return dividend;
}

/**
 * Prints an array of integers.
 * 
 * @param array Pointer to the integer array
 * @param size Number of elements in the array
 */
void print_array(const int *array, size_t size) {
    if (array == NULL || size == 0) {
        printf("(empty array)\n");
        return;
    }
    
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * Counter structure to replace global state.
 */
typedef struct {
    int value;
} Counter;

/**
 * Initializes a counter.
 * 
 * @param counter Pointer to the counter to initialize
 */
void counter_init(Counter *counter) {
    if (counter != NULL) {
        counter->value = 0;
    }
}

/**
 * Increments a counter.
 * 
 * @param counter Pointer to the counter to increment
 */
void counter_increment(Counter *counter) {
    if (counter != NULL) {
        counter->value++;
    }
}

/**
 * Gets the current counter value.
 * 
 * @param counter Pointer to the counter
 * @return Current counter value, or -1 if counter is NULL
 */
int counter_get_value(const Counter *counter) {
    if (counter == NULL) {
        return -1;
    }
    return counter->value;
}

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    size_t array_size = sizeof(numbers) / sizeof(numbers[0]);
    
    printf("Array contents: ");
    print_array(numbers, array_size);
    
    int result = safe_division_with_check(20, 4);
    printf("Safe division result: %d\n", result);
    
    Counter my_counter;
    counter_init(&my_counter);
    counter_increment(&my_counter);
    counter_increment(&my_counter);
    printf("Counter value: %d\n", counter_get_value(&my_counter));
    
    return 0;
}
