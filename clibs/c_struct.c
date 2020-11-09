#include <stdio.h>

struct point_1 {
    int x;
    int y;
    char label;  // 2 bytes
};

struct point_2 {
    int x;
    int y;
    char label_1;
    char label_2;
};

void ex1()
{
    printf("Size of point_1 %lu\n", sizeof(struct point_1));
    printf("Size of point_2 %lu\n", sizeof(struct point_2));

    int n = 5;
    int *ptr = &n;

    printf("Size of point_1* point_2* ptr*: %lu %lu %lu\n",
        sizeof(struct point_1*), sizeof(struct point_2*), sizeof(int*));
}


int main(int argc, char const *argv[])
{
    ex1();
    return 0;
}