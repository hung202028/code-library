#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// string is a sequence of characters terminated with ASCII NUL character.
// the ASCII NUL character is represented as \0.

// strings are commonly stored in array or allocated from the heap. However,
// not all array of character are strings, an array of character may not
// contains NUL character.

void c5_ex1() {
    // string literal | string pool
    const char *s = "hello_world";
    const char *q = "hello_world";
    printf("%d\n", s == q);
}

void c5_ex2() {
    char *error = "ERROR: ";
    char *message = "Not enough memory";

    char *buffer = (char *) malloc(strlen(error) + strlen(message) + 1);
    strcpy(buffer, error);
    strcat(buffer, message);

    printf("%s\n", buffer);
    free(buffer);
}

void c5_ex3() {
    const char *error_const = "Error: ";
    const char *message_const = "Not enough memory";

    char *error = (char *) malloc(strlen(error_const) + 1);
    char *message = (char *) malloc(strlen(message_const) + 1);
    strcpy(error, error_const);
    strcpy(message, message_const);


    // Must re-allocate memory since strcat does not allocate memory
    const size_t len = strlen(error) + strlen(message) + 1;
    error = (char *) realloc(error, len);
    strcat(error, message);
    printf("%s\n", error);

    free(error);
    free(message);
}

size_t _c5_strlen(const char *str) {
    size_t len = 0;

    while (*(str++)) {
        len++;
    }

    return len;
}

void c5_ex4() {
    char *buffer = "Error: not enough memory";
    printf("%zu\n", _c5_strlen(buffer));
}

// return the address of dynamically allocated memory
char *_c5_blank(size_t size) {
    char *buffer = (char *) malloc(size + 1);
    if (buffer == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < size; ++i) {
        buffer[i] = ' ';
    }

    buffer[size] = '\0';
    return buffer;
}

void c5_ex5() {
    char *buffer = _c5_blank(10);
    printf("%lu\n", strlen(buffer));
    free(buffer);
}

char *_c5_lower(const char *input_str) {
    if (input_str == NULL) { return NULL; }
    char *tmp = (char *) malloc(strlen(input_str) + 1);
    char *buffer = tmp;

    while (*input_str != 0) {
        *(tmp++) = tolower(*(input_str++));
    }
    *tmp = 0;

    return buffer;
}

void c5_ex6() {
    char *s = _c5_lower("Not Enough Memory");
    printf("%s %lu\n", s, strlen(s));
    free(s);
}


int _c5_compare(const char *s1, const char *s2, int ignore_case) {
    if (ignore_case == 0) {
        return strcmp(s1, s2);
    }

    if (ignore_case == 1) {
        char *t1 = _c5_lower(s1);
        char *t2 = _c5_lower(s2);

        int result = strcmp(t1, t2);

        free(t1);
        free(t2);

        return result;
    }

    return 0;
}

typedef int (*fptr_operation)(const char *, const char *);


int _c5_strcmp(const char *s1, const char *s2) {
    return _c5_compare(s1, s2, 0);
}

int _c5_strcmp_ignore_case(const char *s1, const char *s2) {
    return _c5_compare(s1, s2, 1);
}

void _c5_printf(char *names[], size_t size) {
    if (names == NULL) {
        printf("%s\n", "[]");
    }

    printf("%c", '[');

    for (size_t i = 0; i < size; ++i) {
        printf("%s", names[i]);
        if (i < size - 1) {
            printf("%c", ',');
        }
    }

    printf("%c\n", ']');
}

// bubble sort with flag optimization
void _c5_sort(char *names[], size_t size, fptr_operation func) {
    int swap = 1;
    while (swap) {
        swap = 0;

        for (size_t i = 0; i < size - 1; ++i) {
            if (func(names[i], names[i + 1]) > 0) {
                swap = 1;
                char *tmp = names[i];
                names[i] = names[i + 1];
                names[i + 1] = tmp;
            }
        }
    }
}


void c5_ex7() {
    char *names_a[] = {"Bob", "Ted", "Carol", "Alice", "alice"};
    char *names_b[] = {"Bob", "Ted", "Carol", "Alice", "alice"};
    const size_t size = sizeof(names_a) / sizeof(char *);

    _c5_sort(names_a, size, _c5_strcmp);
    _c5_sort(names_b, size, _c5_strcmp_ignore_case);

    _c5_printf(names_a, size);
    _c5_printf(names_b, size);
}

void c5_run() {
    c5_ex7();
}