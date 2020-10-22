#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array is a contigious collection of elems that can be accessed using an index
// Elements of an array are adjacent to one another in memory with no gaps
// between them.

void _c4_free(void **ptr) {
    if (ptr != NULL && *ptr != NULL) {
        free(*ptr);
        *ptr = NULL;
    }
}

char *_c4_getline() {
    const int increment_block = 10;
    char *buffer = (char *) malloc(increment_block);

    if (buffer == NULL) {
        return NULL;
    }

    char *current_position = buffer;
    size_t current_length = 0;
    size_t max_length = increment_block;

    int input_char;
    while (1) {
        input_char = fgetc(stdin);
        if (input_char == '\n') {
            break;
        }

        if (++current_length >= max_length) {
            max_length += increment_block;
            char *new_buffer = (char *) realloc(buffer, max_length);
            if (new_buffer == NULL) {
                _c4_free((void *) &(buffer));
                return NULL;
            }
            current_position = new_buffer + (current_position - buffer);
            buffer = new_buffer;
        }

        *current_position++ = input_char;
    }

    *current_position = '\0';
    return buffer;
}

void c4_ex1() {
    printf("%s: ", "Enter your message");
    char *data = _c4_getline();
    printf("You entered: %s", data);

    _c4_free((void *) &(data));
}

char *_c4_trim(char *phrase) {
    char *old = phrase;
    char *new = phrase;

    while (*old == ' ') {
        old++;
    }

    while (*old && *old != ' ') {
        *(new++) = *(old++);
    }

    *new = 0;
    return (char *) realloc(phrase, strlen(phrase) + 1);
}

void c4_ex2() {
    char *str = (char *) malloc(strlen("   cat  ") + 1);
    strcpy(str, "   cat  ");
    printf("%s\n", _c4_trim(str));
    printf("%lu\n", strlen(str));
    _c4_free((void *) &(str));
}

void _c4_array_non_contigious() {
    int rows = 2;
    int cols = 5;

    // Allocate
    int **arr = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr[i] = (int *) malloc(cols * sizeof(int));
    }

    // Free
    for (int i = 0; i < rows; i++) {
        _c4_free((void *) &(arr[i]));
    }

    _c4_free((void *) &(arr));
}

void _c4_array_contigious() {
    int rows = 2;
    int cols = 5;

    int *arr = (int *) malloc(rows * cols * sizeof(int));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(arr + (i * cols) + j) = i * j;
        }
    }

    _c4_free((void*)&(arr));
}

void c4_ex3() {
    _c4_array_non_contigious();
    _c4_array_contigious();
}

void c4_run() {
    c4_ex3();
}