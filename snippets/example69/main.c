#include <stdio.h>

// #region demo
#include <stdio.h>

enum TrafficLight {
    RED,
    YELLOW,
    GREEN
};

void print_action(enum TrafficLight state) {
    switch (state) {
        case RED:
            printf("STOP - Do not go\n");
            break;
        case YELLOW:
            printf("CAUTION - Slow down\n");
            break;
        case GREEN:
            printf("GO - You may go\n");
            break;
        default:
            printf("Unknown state\n");
    }
}
// #endregion demo

int main(void) {
    print_action(RED);
    print_action(GREEN);
    return 0;
}
