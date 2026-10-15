// #region demo
#include <stdio.h>

struct Student {
    char name[50];
    int age;
    float grade;
};

int main() {
    struct Student student1 = {"Marco Rossi", 20, 28.5};
    
    printf("Name: %s\n", student1.name);
    printf("Age: %d\n", student1.age);
    printf("Grade: %.2f\n", student1.grade);
    
    return 0;
}
// #endregion demo
