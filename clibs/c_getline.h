#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 32

#ifndef CLIBS_C_GETLINE_H
#define CLIBS_C_GETLINE_H

char *c_getline() {
    char *buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        return NULL;
    }

    char *current_position = buffer;
    size_t current_length = 0;
    size_t maximum_length = BUFFER_SIZE;
    int input_char = 0;

    while (1) {
        input_char = fgetc(stdin);
        if (input_char == '\n') {
            break;
        }

        if (++current_length > maximum_length) {
            maximum_length += BUFFER_SIZE;
            char *new_buffer = (char *) realloc(buffer, maximum_length);
            if (new_buffer == NULL) {
                free(buffer);
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

char *system_getline() {
    char *buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
    size_t size_buffer = BUFFER_SIZE * sizeof(char);

    ssize_t result = getline(&buffer, &size_buffer, stdin);
    if (result < 0) {
        free(buffer);
        return NULL;
    }

    return buffer;
}

#endif
