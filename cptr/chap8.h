#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

// The "restrict" keyword has two implications:
// 1.To the compiler it means it can performs code optimization
// 2. To the developer it means these pointers should not be aliased (should
// not point to the same memory address).


typedef struct _c8_factorialData {
    int number;
    int result;

    void (*callBack)(struct _c8_factorialData *);
} C8_FactorialData;

void _c8_free(C8_FactorialData** data) {
    if (data != NULL && *data != NULL) {
        free(*data);
        *data = NULL;
    }
}

void _c8_factorial(void *args) {
    C8_FactorialData *factorialData = (C8_FactorialData *) args;
    void (*callBack)(C8_FactorialData *); // Function prototype
    int number = factorialData->number;
    callBack = factorialData->callBack;
    int num = 1;
    for (int i = 1; i <= number; i++) {
        num *= i;
    }
    factorialData->result = num;
    callBack(factorialData);
    pthread_exit(NULL);
}

void _c8_startThread(C8_FactorialData *data) {
    pthread_t thread_id;
    int thread = pthread_create(&thread_id, NULL, (void *) _c8_factorial,
                                (void *) data);
}

void _c8_callBackFunction(C8_FactorialData *factorialData) {
    printf("Factorial is %d\n", factorialData->result);
}

void c8_ex1() {
    C8_FactorialData *data =
            (C8_FactorialData *) malloc(sizeof(C8_FactorialData));
    if (!data) {
        printf("Failed to allocate memory\n");
        return;
    }
    data->number = 5;
    data->callBack = _c8_callBackFunction;
    _c8_startThread(data);

    printf("Program can perform other task concurrently");
    sleep(5);
}


void c8_run() {
    c8_ex1();
}