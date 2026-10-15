#include <stdio.h>

int main(void) {
    // #region state
    int state;
    printf("Machine state (0=stopped, 1=running, 2=fault): ");
    scanf("%d", &state);

    switch (state) {
        case 0:
            printf("Machine stopped\n");
            break;

        case 1:
            printf("Machine running\n");
            break;

        case 2:
            printf("Fault: call maintenance\n");
            break;

        default:
            printf("Unknown state\n");
    }
    // #endregion
    return 0;
}
