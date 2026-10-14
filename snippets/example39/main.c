#include <stdio.h>

int main(void) {
    // #region snippet1
    int temperature = 72;
    int limit = 80;

    printf("%d\n", temperature < limit);    // 1 (true)
    printf("%d\n", temperature == limit);   // 0 (false)
    printf("%d\n", temperature != limit);   // 1 (true)
    printf("%d\n", temperature + 10 > limit); // 1: 82 > 80
    // #endregion snippet1

    // #region snippet2
    int door_closed = 1;
    int emergency = 0;
    int motor_temperature = 72;
    int max_temperature = 80;
    int motor_ok = (motor_temperature < max_temperature) && door_closed && !emergency;
    int must_stop = emergency || (motor_temperature >= max_temperature);

    printf("Motor can run: %d\n", motor_ok);   // 1
    printf("Must stop: %d\n", must_stop);      // 0
    // #endregion snippet2

    // #region snippet3
    double sum = 0.1 + 0.2;
    printf("%d\n", sum == 0.3);   // 0: rounding error!
    // #endregion snippet3
    return 0;
}
