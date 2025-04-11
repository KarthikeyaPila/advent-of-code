#ifndef AOC_UTILS_H
#define AOC_UTILS_H

char *read_file_to_string(const char *filename);
char **split_string(const char *input, const char *delim, int *count_out);
int *convert_strings_to_ints(char **strs, int count);
void free_string_array(char **arr, int count);
int* string_to_digit_array(char* str, int* out_len);
int **parse_2d_int_grid(const char *input_str, int *rows, int *cols);

#endif
