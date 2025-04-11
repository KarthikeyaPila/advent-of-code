#include "aoc_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *read_file_to_string(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        perror("Failed to open file");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *buffer = malloc(size + 1);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(fp);
        return NULL;
    }

    fread(buffer, 1, size, fp);
    buffer[size] = '\0';

    fclose(fp);
    return buffer;
}

char **split_string(const char *input, const char *delim, int *count_out) {
    int count = 0;
    char *copy = strdup(input); // Make a mutable copy
    char *token = strtok(copy, delim);

    // Count tokens first
    while (token) {
        count++;
        token = strtok(NULL, delim);
    }

    free(copy);

    char **result = malloc(sizeof(char*) * count);
    copy = strdup(input);
    token = strtok(copy, delim);

    for (int i = 0; i < count; i++) {
        result[i] = strdup(token);
        token = strtok(NULL, delim);
    }

    free(copy);
    *count_out = count;
    return result;
}

int *convert_strings_to_ints(char **strs, int count) {
    int *ints = malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        ints[i] = atoi(strs[i]);
    }
    return ints;
}

void free_string_array(char **arr, int count) {
    for (int i = 0; i < count; i++) {
        free(arr[i]);
    }
    free(arr);
}

int* string_to_digit_array(char* str, int* out_len) {
    int* result = malloc(100 * sizeof(int)); // Arbitrary large number for now
    int count = 0;
    char* token = strtok(str, " \n");
    while (token != NULL) {
        result[count++] = atoi(token);
        token = strtok(NULL, " \n");
    }
    *out_len = count;
    return result;
}

int **parse_2d_int_grid(const char *input_str, int *rows, int *cols) {
    int line_count;
    char **lines = split_string(input_str, "\n", &line_count);
    *rows = line_count;

    // We'll parse the first line to figure out how many columns
    int col_count;
    char **first_line_parts = split_string(lines[0], " ", &col_count);
    *cols = col_count;
    free_string_array(first_line_parts, col_count);

    // Allocate the grid
    int **grid = malloc(line_count * sizeof(int *));
    for (int i = 0; i < line_count; i++) {
        int word_count;
        char **parts = split_string(lines[i], " ", &word_count);

        grid[i] = malloc(word_count * sizeof(int));
        for (int j = 0; j < word_count; j++) {
            grid[i][j] = atoi(parts[j]);
        }
        free_string_array(parts, word_count);
    }

    free_string_array(lines, line_count);
    return grid;
}
