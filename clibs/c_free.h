//
// Created by hung on 10/26/20.
//

#include <stdlib.h>

#ifndef CLIBS_C_FREE_H
#define CLIBS_C_FREE_H

void c_free(void** ptr) {
    if (ptr != NULL && *ptr != NULL) {
        free(*ptr);
        *ptr = NULL;
    }
}

#endif //CLIBS_C_FREE_H
