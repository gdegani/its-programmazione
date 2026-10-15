#include <stdio.h>
#include <string.h>

int main(void) {
    struct Student {char name[50]; int age; float grade;};
    // #region demo
    struct Student s1;

    // Assignment
    s1.age = 20;
    s1.grade = 28.5;
    strcpy(s1.name, "Marco Rossi");

    // Reading
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("Grade: %.2f\n", s1.grade);

    // Update
    s1.grade = 30.0;
    s1.age++;
    // #endregion demo
    return 0;
}
