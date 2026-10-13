#include <stdint.h>
#include <stdio.h>

// #region snippet1
#define DOOR_OPEN (1u << 0)
#define EMERGENCY (1u << 1)
#define MOTOR_ON  (1u << 2)
#define OVER_TEMP (1u << 3)
// #endregion snippet1

static void print_status(const char *label, uint8_t status) {
    printf("%-14s ", label);
    for (int i = 7; i >= 0; i--) {
        putchar(((status >> i) & 1u) ? '1' : '0');
    }
    printf("  (0x%02X)\n", status);
}

int main(void) {
    // #region snippet2
    uint8_t status = 0;
    print_status("start", status);

    status |= MOTOR_ON;     // set a bit
    status |= DOOR_OPEN;
    print_status("motor, door", status);

    status &= ~DOOR_OPEN;   // clear a bit
    print_status("door closed", status);

    status ^= OVER_TEMP;    // toggle a bit
    print_status("over temp", status);

    if (status & OVER_TEMP) {   // test a bit
        printf("ALARM: temperature too high\n");
    }
    // #endregion snippet2

    return 0;
}
