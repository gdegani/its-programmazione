#include <stdio.h>
#include <string.h>

// #region part1
typedef struct {
    char name[50];
    int age;
    float grade;
} Student;

int main() {
    Student students[3];

    strcpy(students[0].name, "Marco");
    students[0].age = 20;
    students[0].grade = 28.5;

    strcpy(students[1].name, "Anna");
    students[1].age = 19;
    students[1].grade = 27.0;
// #endregion part1

// #region part2
    // Print all the students
    for (int i = 0; i < 2; i++) {
        printf("%s: %.1f\n", students[i].name, students[i].grade);
    }

    return 0;
}
// #endregion part2
