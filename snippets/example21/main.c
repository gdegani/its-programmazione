#include <stdio.h>

void add(int a, int b, int *result) {
    *result = a + b;
    printf("Risultato: %d\n", *result);
}

int main(void) {
    printf("Hello, World!\n");

    int a = 5, b = 3, result = 0;
    printf("a: %d, b: %d\n", a, b);

    add(a, b, &result);

    printf("Risultato: %d\n", result);

    return 0;
}
