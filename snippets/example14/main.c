#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utility.h"

#define MAX 1000

int main(int argc, char *argv[]) {
    char buffer[MAX];

    // Prompt the user to enter a string
    printf("Enter a string: ");

    // Use fgets instead of gets for safer input handling
    if (fgets(buffer, MAX, stdin) != NULL) {
        // Remove the newline character if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }

        // Check if the string is a palindrome and print the result
        if (isPalindrome(buffer)) {
            printf("The string is a palindrome\n");
        } else {
            printf("The string is not a palindrome\n");
        }
    } else {
        // Handle input error
        printf("Error reading string\n");
    }

    return EXIT_SUCCESS;
}