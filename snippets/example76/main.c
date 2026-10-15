#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

// #region demo
void printStudent(struct Student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Grade: %.2f\n", s.grade);
}

int main() {
    struct Student s1 = {"Marco", 20, 28.5};
    printStudent(s1);  // Copies the whole structure
    return 0;
}
// #endregion demo
