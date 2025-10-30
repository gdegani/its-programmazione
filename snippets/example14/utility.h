#ifndef EXAMPLE14_UTILITY_H
#define EXAMPLE14_UTILITY_H

int isPalindrome(char *str);

/**
 * Function to print a slice of a vector of integers
 * @param array - Pointer to the array
 * @param left - Pointer to the left character
 * @param right - Pointer to the right character
 */
void printArray( int array[ ] , int left, int right );


/**
 * Function to remove spaces from a string
 * @param strin input string
 * @param strout output string
 * @param length input string length
 */
void togliSpazi( char *strin, char *strout, int length);

#endif //EXAMPLE14_UTILITY_H
