#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_free.h"
#include "c_getline.h"

#define LINE_LIMIT 50

#ifndef CLIBS_C_RANDOM_FILE_H
#define CLIBS_C_RANDOM_FILE_H

struct c_data {
    char line[LINE_LIMIT];
};

struct c_data *c_input_data(const char *input_str) {
    struct c_data *data = (struct c_data *) malloc(sizeof(struct c_data));

    if (input_str == NULL || strlen(input_str) > LINE_LIMIT) {
        perror("Error: line input exceed length limit");
        strcpy(data->line, "");
    } else {
        strcpy(data->line, input_str);
    }

    return data;
}

size_t c_create_random_file(const char *filename) {
    FILE *fp = NULL;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error: Can't open file");
        return 0;
    }

    while (1) {
        printf("%s: ", "Input line");
        const char *input_line = c_getline();
        if (input_line != NULL && strcmp(input_line, "stop") == 0) {
            c_free((void *) &(input_line));
            break;
        }

        struct c_data *data = c_input_data(input_line);
        fwrite(data, sizeof(struct c_data), 1, fp);
        c_free((void *) &(input_line));
        c_free((void *) &(data));
    }

    fclose(fp);
    return 1;
}

void c_read_random_file(const char *filename) {
    FILE *fp = NULL;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error: Can't open file");
        return;
    }

    fseek(fp, 0L, SEEK_END);
    long end_pos = ftell(fp);
    rewind(fp);
    long start_pos = ftell(fp);

    long rows = (end_pos - start_pos) / ((long) sizeof(struct c_data));

    for (int i = 0; i < rows; ++i) {
        struct c_data *data = (struct c_data *) malloc(sizeof(struct c_data));
        fread(data, sizeof(struct c_data), 1, fp);
        printf("Readed: %s\n", data->line);
        c_free((void *) &(data));
    }
    fclose(fp);
}


#endif //CLIBS_C_RANDOM_FILE_H
