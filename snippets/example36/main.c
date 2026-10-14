#include <stdio.h>

int main(void) {
    // #region snippet1
    int rpm = 1500;
    float temperature = 72.5;
    char status = 'R';

    printf("Machine started\n");
    printf("Speed: %d rpm\n", rpm);
    printf("Temperature: %f\n", temperature);
    printf("Status: %c\n", status);
    printf("%d rpm at %.1f C, status %c\n", rpm, temperature, status);
    // #endregion snippet1

    // #region snippet2
    printf("[%5d]\n", rpm);          // right-aligned in 5 characters
    printf("[%-6d]\n", rpm);         // left-aligned in 6 characters
    printf("[%.2f]\n", temperature); // 2 decimals
    printf("[%8.2f]\n", temperature); // 8 characters, 2 decimals
    // #endregion snippet2
    return 0;
}
