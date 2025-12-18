/*
 * Example: Tests generated with AI assistance
 * 
 * AI Prompt used:
 * "Generate comprehensive test cases for the max2 function using assert().
 *  Include edge cases with INT_MAX, INT_MIN, equal values, and typical cases.
 *  Create a main() that runs all tests and reports results."
 */

#include <stdio.h>
#include <assert.h>
#include <limits.h>

/**
 * Returns the maximum of two integers.
 */
int max2(int a, int b) {
    return a > b ? a : b;
}

void test_max2_positive_numbers(void) {
    assert(max2(5, 3) == 5);
    assert(max2(10, 20) == 20);
    printf("✓ Test: positive numbers passed\n");
}

void test_max2_negative_numbers(void) {
    assert(max2(-5, -3) == -3);
    assert(max2(-10, -20) == -10);
    printf("✓ Test: negative numbers passed\n");
}

void test_max2_mixed_signs(void) {
    assert(max2(-5, 3) == 3);
    assert(max2(10, -20) == 10);
    assert(max2(0, -5) == 0);
    printf("✓ Test: mixed signs passed\n");
}

void test_max2_equal_values(void) {
    assert(max2(5, 5) == 5);
    assert(max2(0, 0) == 0);
    assert(max2(-10, -10) == -10);
    printf("✓ Test: equal values passed\n");
}

void test_max2_edge_cases(void) {
    assert(max2(INT_MAX, 100) == INT_MAX);
    assert(max2(INT_MIN, -100) == -100);
    assert(max2(INT_MAX, INT_MIN) == INT_MAX);
    printf("✓ Test: edge cases passed\n");
}

void test_max2_zero_values(void) {
    assert(max2(0, 5) == 5);
    assert(max2(-5, 0) == 0);
    assert(max2(0, 0) == 0);
    printf("✓ Test: zero values passed\n");
}

int main(void) {
    printf("Running test suite for max2()...\n\n");
    
    test_max2_positive_numbers();
    test_max2_negative_numbers();
    test_max2_mixed_signs();
    test_max2_equal_values();
    test_max2_edge_cases();
    test_max2_zero_values();
    
    printf("\n✅ All tests passed!\n");
    
    return 0;
}
