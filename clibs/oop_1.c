#include <stdio.h>
#include <stdlib.h>
#include "oop_1.h"

#define MAX_SIZE 10

typedef int bool_t;

typedef struct list_t
{
    size_t size;
    int* items;
} list_t;

void __free(void** ptr)
{
    if (ptr != NULL && *ptr != NULL) {
        free(*ptr);
        *ptr = NULL;
    }
}

bool_t __list_full(struct list_t* list)
{
    return (list->size == MAX_SIZE);
}

bool_t __list_check_index(struct list_t* list, int index)
{
    return (index >= 0 && index < list->size);
}

struct list_t* list_malloc()
{
    return (struct list_t*) malloc(sizeof(struct list_t));
}

void list_init(struct list_t* list)
{
    list->size = 0;
    list->items = (int*) malloc(MAX_SIZE * sizeof(int));
}

void list_destroy(struct list_t** list)
{
    __free((void*)&((*list)->items));
    __free((void*)&(*list));
}

int list_add(struct list_t* list, const int value)
{
    if (__list_full(list)) {
        return -1;
    }

    list->items[list->size++] = value;

    return 0;
}

int list_get(struct list_t* list, const int index, int* result)
{
    if (__list_check_index(list, index)) {
        *result = list->items[index];
        return 0;
    }
    return -1;
}

void list_clear(struct list_t* list)
{
    list->size = 0;
}

size_t list_size(struct list_t* list)
{
    return list->size;
}

void list_print(struct list_t* list)
{
    printf("%s", "[");
    for (size_t i = 0; i < list->size; i++) {
        printf("%d", list->items[i]);
        if (i < list->size - 1) {
            printf("%s", ", ");
        }
    }
    printf("%s\n", "]");
}




























