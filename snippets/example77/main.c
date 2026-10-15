#include <stdio.h>

// #region demo
struct Student {
    char name[50];
    int age;
    float grade;
};

void modifyStudent(struct Student *s) {
    s->age = 21;           // Same as (*s).age = 21
    s->grade = 30.0;        // Same as (*s).grade = 30.0
}

int main() {
    struct Student s1 = {"Marco", 20, 28.5};
    modifyStudent(&s1);    // Passes the address
    printf("New age: %d\n", s1.age);  // Prints 21
    return 0;
}
// #endregion demo
