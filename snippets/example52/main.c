#include <stdio.h>

int main(void) {
    // #region demo
    char grade;
    printf("Enter the grade (A-F): ");
    scanf(" %c", &grade);

    switch (grade) {
        case 'A':
        case 'a':
            printf("Excellent!\n");
            break;
        
        case 'B':
        case 'b':
            printf("Good\n");
            break;
        
        case 'C':
        case 'c':
            printf("Sufficient\n");
            break;
        
        default:
            printf("Invalid grade\n");
    }
    // #endregion demo
    return 0;
}
