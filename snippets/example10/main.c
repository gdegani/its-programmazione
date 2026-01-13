#include <stdio.h>
#include <string.h>

/* String length and concatenation */
int main() {
    char greeting[50] = "Hello";
    char name[30] = "World";
    
    /* Find length of string */
    int len_greeting = strlen(greeting);
    printf("Length of '%s': %d\n", greeting, len_greeting);
    
    /* Concatenate strings */
    strcat(greeting, " ");
    strcat(greeting, name);
    printf("Combined: %s\n", greeting);
    
    /* Copy string */
    char copy[50];
    strcpy(copy, greeting);
    printf("Copy: %s\n", copy);
    
    return 0;
}
