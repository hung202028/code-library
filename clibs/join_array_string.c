#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK 1024

char* join_array(char** arr, size_t size)
{
    size_t increment_block = BLOCK * sizeof(char) + sizeof(char);
    size_t max_length = increment_block;

    char* buffer = (char*) malloc(max_length);

    if (buffer == NULL) {
        return NULL;
    }

    buffer[0] = '\0';

    size_t current_length = 0;

    for (size_t i = 0; i < size; ++i) {
        char* word = arr[i];
        size_t word_length = strlen(word);

        current_length += word_length;
        if (current_length > max_length) {
            max_length += increment_block;
            char* new_buffer = (char*) realloc(buffer, max_length);
            if (new_buffer == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = new_buffer;
        }
        strcat(buffer, word);
    }

    return buffer;
}

int main(int argc, char const *argv[])
{
    char s[100];
    char q[100];
    char r[100];

    strcpy(s, "1 2 3 4 5 #");
    strcpy(q, "6 7 8 9 0 #");
    strcpy(r, "3 3 3 3 3 3 3 3 3 #");

    char* arr[3];
    arr[0] = s;
    arr[1] = q;
    arr[2] = r;

    char* string = join_array(arr, 3);
    printf("Result: %s\n", string);

    free(string);

    return 0;
}