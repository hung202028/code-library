#include <stdio.h>
#include "oop_1.h"



int main(int argc, char const *argv[])
{
    struct list_t* list_a = list_malloc();
    struct list_t* list_b = list_malloc();

    list_init(list_a);
    list_init(list_b);

    int data[4] = {1, 2, 3, 4};
    for (size_t i = 0; i < sizeof(data) / sizeof(int); ++i)
    {
        list_add(list_a, data[i]);
    }

    list_print(list_a);

    list_destroy(&list_a);
    list_destroy(&list_b);

    return 0;
}