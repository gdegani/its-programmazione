#include "utility.h"
#include <string.h>
#include <stdio.h>

// Define a debug flag based on the __DEBUG__ macro
#ifdef __DEBUG__
int its_debug = 1;
#else
int its_debug = 0;
#endif

// Function to print debug information if debugging is enabled
void printDebug(char *sx, char *dx) {
    if (its_debug) {
        printf("%c = %c\n", *sx, *dx);
    }
}

// Function to check if a given string is a palindrome
int isPalindrome(char *str) {
    int result = 0;
    char *indice_sx, *indice_dx;

    // Initialize pointers to the start and end of the string
    indice_sx = str;
    indice_dx = indice_sx + strlen(str) - 1;

    // Print initial debug information
    printDebug(indice_sx, indice_dx);

    // Compare characters from the start and end of the string
    while (indice_sx < indice_dx && *indice_sx++ == *indice_dx--) {
        printDebug(indice_sx, indice_dx);
    }

    // Check if the pointers have crossed and the characters are equal
    if (*--indice_sx == *++indice_dx) {
        result = 1;
    }

    return result;
}


struct coordinate {
    int x, y, z;
};

void test(void) {
    struct coordinate punto1, punto2, *punto3;
    struct coordinate punto4 = {1.0, 2.2, 3.4};

    punto2.x = punto4.x;
    punto2.y = punto4.y;

    (*punto3).x = punto4.x;
    punto3->x = punto4.x;


    typedef struct record {
        char name[20];
        char surname[20];
        int age;
    } user_record;

    user_record user1, user2;

    user1.age = 20;
    strcpy(user1.name, "Mario");
}

