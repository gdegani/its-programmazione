#include <stdio.h>
#include <stdlib.h>

// #region snippet1
typedef struct Reading {
    long timestamp;
    int sensor_id;
    double value;
    struct Reading *next;
} Reading;

// Insert a new reading at the head of the list
Reading *push(Reading *head, long timestamp, int sensor_id, double value) {
    Reading *node = malloc(sizeof(Reading));
    if (node == NULL) {
        return head;
    }
    node->timestamp = timestamp;
    node->sensor_id = sensor_id;
    node->value = value;
    node->next = head;
    return node;
}

void free_list(Reading *head) {
    while (head != NULL) {
        Reading *next = head->next;
        free(head);
        head = next;
    }
}
// #endregion snippet1

// #region snippet2
int main(void) {
    FILE *file = fopen("readings.csv", "r");
    if (file == NULL) {
        perror("Cannot open readings.csv");
        return EXIT_FAILURE;
    }

    Reading *head = NULL;
    char line[100];
    while (fgets(line, sizeof(line), file) != NULL) {
        long timestamp;
        int sensor_id;
        double value;
        if (sscanf(line, "%ld;%d;%lf", &timestamp, &sensor_id, &value) == 3) {
            head = push(head, timestamp, sensor_id, value);
        }
    }
    if (ferror(file)) {
        perror("Cannot read readings.csv");
        fclose(file);
        free_list(head);
        return EXIT_FAILURE;
    }
    fclose(file);

    int count = 0;
    double sum = 0.0;
    double max = 0.0;
    for (Reading *r = head; r != NULL; r = r->next) {
        if (count == 0 || r->value > max) {
            max = r->value;
        }
        sum += r->value;
        count++;
    }

    if (count > 0) {
        printf("Readings: %d, average: %.2f, max: %.2f\n", count, sum / count, max);
    }

    free_list(head);
    return EXIT_SUCCESS;
}
// #endregion snippet2
