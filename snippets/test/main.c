#include <stdio.h>


void somma(int a, int b, int c) {
    c = a + b;
}

void main(void) {
    int x = 5;
    int y = 2;
    int z = 0;
    somma(x, y, z);
    printf("The value is: %d\n", z);
}
