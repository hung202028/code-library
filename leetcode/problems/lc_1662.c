// https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BLOCK 10240

char* join_array(char** arr, size_t size)
{
    size_t max_length = BLOCK * sizeof(char) + 1;
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
            max_length += BLOCK * sizeof(char) + 1;
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

bool solve(char** arr_1, size_t size_1, char** arr_2, size_t size_2)
{
    char* buffer_1 = join_array(arr_1, size_1);
    char* buffer_2 = join_array(arr_2, size_2);

    int result = strcmp(buffer_1, buffer_2);
    free(buffer_1);
    free(buffer_2);

    return (result == 0) ? true : false;
}

int main(int argc, char const *argv[])
{
    char a1[100];
    char a2[100];
    char b1[100];
    char b2[100];

    strcpy(a1, "a");
    strcpy(a2, "bc");

    strcpy(b1, "ab");
    strcpy(b2, "c ");

    char* w1[2] = {a1, a2};
    char* w2[2] = {b1, b2};

    printf("%d\n", solve(w1, 2, w2, 2));


    return 0;
}