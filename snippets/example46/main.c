#include <stdio.h>

int main(void) {
    // #region menu
    int choice;
    int running = 0;

    do {
        printf("\n===== MACHINE MENU =====\n");
        printf("1. Start\n");
        printf("2. Stop\n");
        printf("3. Status\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: running = 1; printf("Started\n"); break;
            case 2: running = 0; printf("Stopped\n"); break;
            case 3: printf("Running: %s\n", running ? "yes" : "no"); break;
            case 0: printf("Bye\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 0);
    // #endregion
    return 0;
}
