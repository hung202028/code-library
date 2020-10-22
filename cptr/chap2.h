#include "stdio.h"
#include "stdlib.h"
#include "string.h"

// calloc: allocate memory from the heap
// realloc: re-allocate memory to a larger or smaller amount base on a
//          previously allocated block of memory

// calloc:  allocate and zero out memory from the heap
// free:    return a block of memory from the heap


//
void c2_ex1() {
    // 1. Allocate memory from the heap and return the first byte's address.
    int *p = (int*) malloc(sizeof(int));
    if (p != NULL) {
        free(p);
    } else {
        printf("%s\n", "Cannot allocate memory");
    }
}

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wuninitialized"
void c2_ex2() {
    char *p; // problem: memory has not been allocated!
    printf("%s: ", "Enter name");
    scanf("%s", p);
}
#pragma clang diagnostic pop

void c2_ex3() {
    // allocate and clear memory at the same time
    // clear memory: set the content to all binary zeros
    int* p1 = (int*) calloc(5, sizeof(int));

    // using malloc and memset to achieve the same result
    int* p2 = (int*) malloc(5 * sizeof(int));
    memset(p2, 0, 5 * sizeof(int));

    free(p1);
    free(p2);
}

void c2_ex4() {
    double* p1 = (double*) malloc(10 * sizeof(double ));
    printf("Address of p1: %p\n", &p1);

    // If the size is zero and the pointer is not null,
    // then the pointer will be freed
    double* p2 = realloc(p1, 0);
    printf("Address of p2: %p\n", &p2);
    printf("Address of p1: %p\n", &p1);

    free(p1);
    free(p2);
}

void c2_ex5() {
    int* p1 = (int*) malloc(sizeof(int));
    *p1 = 1000;

    int* p2;
    p2 = p1;
    free(p1);

    *p2 = 5000; // dangling pointer
    printf("p2[Address: %p, Value: %d]", &p2, *p2);
}


void c2_run() {
    c2_ex5();
}