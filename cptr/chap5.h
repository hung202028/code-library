#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void c5_run() {
    c5_ex3();
}