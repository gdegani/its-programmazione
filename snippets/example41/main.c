#include <stdio.h>

int main(void) {
    // #region pin
    int pin;
    int attempts = 0;
    const int CORRECT_PIN = 1234;
    const int MAX_ATTEMPTS = 3;

    do {
        printf("Enter the PIN (4 digits): ");
        scanf("%d", &pin);
        attempts++;

        if (pin == CORRECT_PIN) {
            printf("Access granted\n");
            break;
        }
        printf("Wrong PIN. Attempts left: %d\n", MAX_ATTEMPTS - attempts);
    } while (attempts < MAX_ATTEMPTS);

    if (attempts == MAX_ATTEMPTS && pin != CORRECT_PIN) {
        printf("Machine panel locked\n");
    }
    // #endregion
    return 0;
}
