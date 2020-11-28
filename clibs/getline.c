#include <stdio.h>
#include <stdlib.h>

#define BLOCK 1024


char* c_getline()
{
    size_t increment_block = BLOCK * sizeof(char) + sizeof(char);
    size_t max_length = increment_block;

    char* buffer = (char*) malloc(max_length);
    if (buffer == NULL) {
        return NULL;
    }

    size_t current_length = 0;
    char* current_position = buffer;

    int input_char;
    while (1) {
        input_char = fgetc(stdin);

        if (input_char == '\n') {
            break;
        }

        if (++current_length > max_length) {
            max_length += increment_block;
            char* new_buffer = (char*) realloc(buffer, max_length);

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

char* sys_getline()
{
    size_t buf_size = BLOCK * sizeof(char) + sizeof(char);
    char* buffer = (char*) malloc(buf_size);

    ssize_t rs = getline(&buffer, &buf_size, stdin);
    if (rs < 0) {
        free(buffer);
        return NULL;
    }

    return buffer;
}

int main(int argc, char const *argv[])
{
    printf("%s: ", "C Getline");
    char* s = c_getline();
    printf("Result: %s\n", s);
    free(s);

    printf("%s: ", "System getline");
    char* q = sys_getline();
    printf("Result: %s\n", q);
    free(q);

    return 0;
}