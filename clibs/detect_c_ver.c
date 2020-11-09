#include <stdio.h>

int main(int argc, char** argv) {
    #if __STDC_VERSION__ >=  201710L
        printf("%s\n", "Hello World from C18!");
    #elif __STDC_VERSION__ >= 201112L
        printf("%s\n", "Hello World from C11!");
    #elif __STDC_VERSION__ >= 199901L
        printf("%s\n", "Hello World from C99!");
    #else
        printf("%s\n", "Hello World from C89/C90!");
    #endif
  return 0;
}