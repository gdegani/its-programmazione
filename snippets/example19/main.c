#include <stdio.h>

// Student struct definition
struct Student {
    char name[50];
    int age;
    float grade;
};

// Function that takes a struct as argument
void printStudent(struct Student s) {
    printf("Name: %s\n", s.name);
    printf("Age: %d\n", s.age);
    printf("Grade: %.2f\n", s.grade);
}

int main() {
    // Declaration and initialization of a struct
    struct Student student1 = {"John Smith", 20, 28.5};

    // Call function with struct as argument
    printStudent(student1);

    return 0;
}
