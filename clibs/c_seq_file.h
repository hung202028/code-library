#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "c_getline.h"
#include "c_free.h"

#ifndef CLIBS_C_SEQ_FILE_H
#define CLIBS_C_SEQ_FILE_H

size_t c_create_seq_file(const char *filename) {
    FILE *fp = NULL;
    fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error: Can't open file");
        return 0;
    }
    const char *line = NULL;

    while (1) {
        printf("%s: ", "Input line");
        line = c_getline();
        if (line == NULL || strcmp(line, "stop") == 0) {
            c_free((void*)&(line));
            break;
        }

        fputs(line, fp);
        c_free((void *) &(line));
    }

    fclose(fp);
    return 1;
}

void c_read_seq_file(const char *filename) {
    FILE *fp = NULL;
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error: can't open file");
        return;
    }

    char buffer[50];
    while (!feof(fp)) {
        fgets(buffer, 50, fp);
        puts(buffer);
    }

    fclose(fp);
}

#endif //CLIBS_C_SEQ_FILE_H
