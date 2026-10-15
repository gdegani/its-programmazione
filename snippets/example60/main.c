// #region demo
#include <stdio.h>

void greet(const char *name) {
    printf("Hello, %s!\n", name);
}

void print_line(void) {
    printf("====================\n");
}

int main(void) {
    print_line();
    greet("Mario");
    greet("Luigi");
    print_line();
    
    return 0;
}
// #endregion demo
