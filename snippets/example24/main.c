#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

int main() {

    int v;
    char choice[5];

    do {
        printf("Available operations:\n");
        printf("a. AddToHead\n");
        printf("b. AddToTail\n");
        printf("c. RemoveFromHead\n");
        printf("d. RemoveFromTail\n");
        printf("e. ClearAll\n");
        printf("p. PrintAll\n");
        printf("x. Exit\n");
        printf("\nChoice: ");
        scanf("%s", choice);

        switch (choice[0]) {
            case 'a':
            case 'A':
                printf("Value to insert: ");
                scanf("%d", &v);
                int returnValue = AddToHead(v);
                if (returnValue == LIST_ERROR)
                    printf("Error!\n");
                break;
            case 'b':
                printf("Value to insert: ");
                scanf("%d", &v);
                if (AddToTail(v) == LIST_ERROR)
                    printf("Error!\n");
                break;
            case 'c':
                if (RemoveFromHead(&v) == LIST_ERROR)
                    printf("Error!\n");
                else
                    printf("Extracted value: %d\n", v);
                break;
            case 'd':
                if (RemoveFromTail(&v) == LIST_ERROR)
                    printf("Error!\n");
                else
                    printf("Extracted value: %d\n", v);
                break;
            case 'e':
                ClearAll();
                break;
            case 'p':
                printAll();
                break;
        }
    } while (choice[0] != 'x');
    return EXIT_SUCCESS;
}
