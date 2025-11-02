#include <stdio.h>

int main(void) {
    int base = 2, height = 3;

    printf("Hello world!\n");
    {
        // Scope example: inner base shadows outer base
        int base = 4;
        int area = base * height;
        printf("Base = %d \n", base);
        printf("Height = %d \n", height);
        printf("Area = %d \n", area);
    }
    printf("Base = %d \n", base);

    getchar();
    return 0;

}
