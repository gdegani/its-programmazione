#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX_NUMBER 100
#define MAX_ATTEMPTS 3

int main(void) {
    int guess, number;
    int max_number = MAX_NUMBER;
    int max_attempts = MAX_ATTEMPTS;

    printf("Welcome to the Number Guessing Game!\n");
    printf("Enter the maximum number to guess (default %d): ", MAX_NUMBER);
    if (scanf("%d", &max_number) != 1) {
        max_number = MAX_NUMBER; // use default on invalid input
    }

    printf("Enter the maximum number of attempts (default %d): ", MAX_ATTEMPTS);
    if (scanf("%d", &max_attempts) != 1) {
        max_attempts = MAX_ATTEMPTS; // use default on invalid input
    }

    srand(time(NULL)); // Seed the random number generator
    number = rand() % (max_number + 1); // Generate a random number between 0 and max_number

    printf("I have selected a number between 0 and %d. Can you guess it?\n", max_number);

    int counter = 0;
    do {
        printf("Please, input your guess: ");
        scanf("%d", &guess);
        printf("You guessed %d!\n", guess);

        if (guess > number) {
            printf("Too high...\n");
        } else if (guess < number) {
            printf("Too low...\n");
        } else {
            printf("Congratulations! You guessed the number!\n");
        }

        counter++;
    } while (guess != number && counter < max_attempts);

    if (guess != number) {
        printf("Sorry, you've used all your attempts. The number was %d.\n", number);
    }

    return 0;
}