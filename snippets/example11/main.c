#include <stdio.h>
#include <string.h>

/* Simple string usage and basic operations */
int main() {
    char name[50];
    
    /* Read string from user */
    printf("Enter your name: ");
    scanf("%s", name);
    
    /* Display string */
    printf("Hello, %s!\n", name);
    
    /* Get string length */
    int length = strlen(name);
    printf("Your name has %d characters\n", length);
    
    /* Display each character */
    printf("Characters: ");
    for (int i = 0; i < length; i++) {
        printf("%c ", name[i]);
    }
    printf("\n");
    
    return 0;
}
