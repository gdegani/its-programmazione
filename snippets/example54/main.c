#include <stdio.h>

int main(void) {
    // #region demo
    int grade = 75;

    if (grade >= 90) {
        printf("Excellent\n");
    } else if (grade >= 75) {
        printf("Good\n");
    } else if (grade >= 60) {
        printf("Sufficient\n");
    } else {
        printf("Insufficient\n");
    }
    // Output: Good
    // #endregion demo
    return 0;
}
