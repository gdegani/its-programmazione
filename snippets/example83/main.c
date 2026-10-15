#include <stdio.h>
#include <stdlib.h>

// #region part1
typedef struct {
  char subject[30];
  int grade;
} Course;

int main() {
  int n;
  printf("Number of courses: ");
  scanf("%d", &n);

  // Allocate memory for n courses
  Course *courses = (Course *)malloc(n * sizeof(Course));
// #endregion part1

// #region part2
  // Read the data
  for (int i = 0; i < n; i++) {
    printf("Subject %d: ", i+1);
    scanf("%s", courses[i].subject);
    printf("Grade: ");
    scanf("%d", &courses[i].grade);
  }

  // Display
  for (int i = 0; i < n; i++) {
    printf("%s: %d\n", courses[i].subject, courses[i].grade);
  }

  free(courses);
  return 0;
}
// #endregion part2
