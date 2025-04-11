#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** read_lines_from_file(const char* filename, int* out_line_count) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("File open failed");
        exit(EXIT_FAILURE);
    }

    char** lines = malloc(sizeof(char*) * 1000); // Up to 200 lines
    char buffer[256];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        lines[count] = malloc(strlen(buffer) + 1);
        strcpy(lines[count], buffer);
        count++;
    }

    fclose(file);
    *out_line_count = count;
    return lines;
}

int* string_to_digit_array(char* str, int* out_len) {
    int* result = malloc(100 * sizeof(int));
    int count = 0;
    char* token = strtok(str, " \n");
    while (token != NULL) {
        result[count++] = atoi(token);
        token = strtok(NULL, " \n");
    }
    *out_len = count;
    return result;
}

int validate_report(int n, int arr[]) {
    int is_increasing = 1;
    int is_decreasing = 1;
    int valid_differences = 1;

    for (int i = 0; i < n - 1; i++) {
        int diff = arr[i + 1] - arr[i];
        if (diff == 0 || diff > 3 || diff < -3) {
            valid_differences = 0;
        }
        if (arr[i] < arr[i + 1]) {
            is_decreasing = 0;
        } else if (arr[i] > arr[i + 1]) {
            is_increasing = 0;
        }
    }

    return valid_differences && (is_increasing || is_decreasing);
}

int main(void) {
    int line_count = 0;
    char** lines = read_lines_from_file("input.txt", &line_count);
    int count = 0;

    for (int i = 0; i < line_count; i++) {
        int len;
        int* arr = string_to_digit_array(lines[i], &len);

        for (int j = 0; j < len; j++) {
            printf("%d ", arr[j]);
        }
        printf("\n");

        if (validate_report(len, arr)) {
            printf("[DEBUG]: VALID\n");
            count++;
        }

        free(arr);
        free(lines[i]);
    }

    free(lines);

    printf("\nTotal valid: %d\n", count);
    return 0;
}
