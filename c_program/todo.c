#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "tasks.txt"
#define MAX_LINE 256

void add_task(const char *task) {
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Could not open file");
        return;
    }
    fprintf(file, "[ ] %s\n", task);
    fclose(file);
    printf("Added: \"%s\"\n", task);
}

void list_tasks(void) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("No tasks yet. Add one with: .\\todo.exe add \"Your task\"\n");
        return;
    }

    char line[MAX_LINE];
    int count = 1;
    printf("\n--- Your Todo List ---\n");
    while (fgets(line, sizeof(line), file)) {
        printf("%d. %s", count++, line);
    }
    if (count == 1) {
        printf("(List is empty)\n");
    }
    printf("----------------------\n\n");
    fclose(file);
}

void complete_task(int task_num) {
    FILE *file = fopen(FILE_NAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    if (!file || !temp) {
        perror("File error");
        if (file) fclose(file);
        if (temp) fclose(temp);
        return;
    }

    char line[MAX_LINE];
    int count = 1;
    int found = 0;

    while (fgets(line, sizeof(line), file)) {
        if (count == task_num) {
            if (strncmp(line, "[ ]", 3) == 0) {
                line[1] = 'x';
            }
            found = 1;
        }
        fputs(line, temp);
        count++;
    }

    fclose(file);
    fclose(temp);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    if (found) {
        printf("Marked task %d as done.\n", task_num);
    } else {
        printf("Task %d not found.\n", task_num);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage:\n");
        printf("  %s add \"Task description\"\n", argv[0]);
        printf("  %s list\n", argv[0]);
        printf("  %s done <task_number>\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "add") == 0 && argc == 3) {
        add_task(argv[2]);
    } else if (strcmp(argv[1], "list") == 0) {
        list_tasks();
    } else if (strcmp(argv[1], "done") == 0 && argc == 3) {
        complete_task(atoi(argv[2]));
    } else {
        printf("Invalid command or missing argument.\n");
    }

    return 0;
}
