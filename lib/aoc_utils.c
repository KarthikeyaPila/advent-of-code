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