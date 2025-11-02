#include <stdio.h>

// Student struct definition
struct Student {
    char name[50];
    int age;
    float grade;
};

// Function that takes a struct as argument
void printStudent(struct Student s) {
    printf("Nome: %s\n", s.name);
    printf("Età: %d\n", s.age);
    printf("Voto: %.2f\n", s.grade);
}

int main() {
    // Declaration and initialization of a struct
    struct Student student1 = {"Marco Rossi", 20, 28.5};

    // Call function with struct as argument
    printStudent(student1);

    return 0;
}
