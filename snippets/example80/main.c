#include <stdio.h>

// #region demo
struct Student {
    char name[50];
    int age;
    float grade;
};

// Direct initialization
struct Student s1 = {"Marco Rossi", 20, 28.5};

// Partial initialization
struct Student s2 = {"Anna"}; // age=0, grade=0.0

// Declaration without initialization
struct Student s3;
// #endregion demo

int main(void) {
    return 0;
}
