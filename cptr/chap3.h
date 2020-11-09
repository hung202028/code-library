#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The program stack is an area of memory that supports execution of functions
// and holds stack_frames (or activation_record | activation_frame)
// Stack frame holds the params and local variables of a function.

// Organization of a stack frame:
// 1. return_address: the address in the program where the function is to return
// upon completion

// 2. storage for local variables and params

// 3. stack and base pointer: used by runtime system to manage the stack

int *_c3_ex1(size_t size, int value) {
//    int arr[size];
//    for (size_t i = 0; i < size; ++i) {
//        arr[i] = value;
//    }
//    return arr;

    return 0;
}

int *_c3_ex2(size_t size, int value) {
    static int arr[1000];
    for (size_t i = 0; i < size; i++) {
        arr[i] = value;
    }

    return arr;
}

int *_c3_ex3(int *arr, size_t size, int value) {
    if (arr != NULL) {
        for (size_t i = 0; i < size; ++i) {
            arr[i] = value;
        }
    }
    return arr;
}

void c3_ex1() {
    int *arr = _c3_ex1(10, 1000);
    for (size_t i = 0; i < 10; ++i) {
        printf("%d\n", arr[i]);
    }
}

void c3_ex2() {
    int *arr = _c3_ex2(5, 7777);
    for (size_t i = 0; i < 5; ++i) {
        printf("%d\n", arr[i]);
    }
}

void c3_ex3() {
    int *arr = (int *) malloc(5 * sizeof(int));
    _c3_ex3(arr, 5, 99999);
    for (size_t i = 0; i < 5; ++i) {
        printf("%d\n", arr[i]);
    }
}

// When a pointer is passed to a function. If we want to modify original pointer
// and not the copy of pointer, we need to pass a pointer to a pointer.

void _c3_ex4(int **arr, size_t size, int value) {
    *arr = (int *) malloc(size * sizeof(int));
    for (size_t i = 0; i < size; ++i) {
        *(*arr + i) = value;
    }
}

void c3_ex4() {
    int *arr = NULL;
    _c3_ex4(&arr, 5, 123456);
    for (size_t i = 0; i < 5; ++i) {
        printf("%d\n", arr[i]);
    }
}

void _c3_free(void **ptr) {
    if (ptr != NULL && *ptr != NULL) {
        free(*ptr);
        *ptr = NULL;
    }
}

void c3_ex5() {
    int *p = (int *) malloc(sizeof(int));
    *p = 5;

    printf("Before: %p\n", p);
    _c3_free((void **) &p);

    printf("After: %p\n", p);
    _c3_free((void **) &p);
}

int _c3_square(int num) {
    return num * num;
}

int _c3_cube(int num) {
    return num * num * num;
}

int (*_c3_fptr1)(int);

void c3_ex6() {
    int n = 5;
    _c3_fptr1 = _c3_square;
    printf("%d square is %d\n", n, _c3_fptr1(n));

    _c3_fptr1 = _c3_cube;
    printf("%d cube is %d\n", n, _c3_cube(n));
}

// passing function pointer
typedef int (*_c3_fptr)(int);
int _c3_compute(_c3_fptr func, int num) {
    return func(num);
}

void c3_ex7() {
    int n = 5;
    int square = _c3_compute(_c3_square, n);
    int cube = _c3_compute(_c3_cube, n);
    printf("%d square is %d\n", n, square);
    printf("%d cube is %d\n", n, cube);
}

// Returning function pointer
int _c3_add(int a, int b) {
    return a + b;
}

int _c3_sub(int a, int b) {
    return a - b;
}

typedef int (*_c3_fptr_op)(int, int);

_c3_fptr_op _c3_select(char opcode) {
    switch (opcode) {
        case '+': return _c3_add;
        case '-': return _c3_sub;
        default: return NULL;
    }
}

int _c3_eval(char opcode, int a, int b) {
    _c3_fptr_op func = _c3_select(opcode);
    return func(a, b);
}

void c3_ex8() {
    int a = 10;
    int b = 5;

    printf("%d + %d = %d\n", a, b, _c3_eval('+', a, b));
    printf("%d - %d = %d\n", a, b, _c3_eval('-', a, b));
}


void c3_run() {
    c3_ex8();
}