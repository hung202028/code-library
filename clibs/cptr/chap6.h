#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct _c6_persion {
    char *firstname;
    char *lastname;
    char *title;
    short age;
} c6_Persion;

void _c6_deallocate_persion(c6_Persion **ptr) {
    if (ptr && *ptr != NULL) {
        free((*ptr)->firstname);
        free((*ptr)->lastname);
        free((*ptr)->title);
        free(*ptr);
        *ptr = NULL;
    }
}

void _c6_initialize_persion(c6_Persion **p,
                            const char *f_name,
                            const char *l_name,
                            const char *title,
                            short age) {
    (*p) = (c6_Persion *) malloc(sizeof(c6_Persion));
    (*p)->firstname = (char *) malloc(strlen(f_name) + 1);
    (*p)->lastname = (char *) malloc(strlen(l_name) + 1);
    (*p)->title = (char *) malloc(strlen(title) + 1);
    (*p)->age = age;

    strcpy((*p)->firstname, f_name);
    strcpy((*p)->lastname, l_name);
    strcpy((*p)->title, title);
}

void _c6_display_persion(c6_Persion **p) {
    if (p == NULL || *p == NULL) {
        printf("NULL");
    }

    printf("%s", "Persion[");
    printf("firstname=%s, ", (*p)->firstname);
    printf("lastname=%s, ", (*p)->lastname);
    printf("title=%s, ", (*p)->title);
    printf("age=%d", (*p)->age);
    printf("%c.", ']');
    printf(" %p\n", *p);
}

void c6_ex1() {
    c6_Persion *p1 = NULL;
    _c6_initialize_persion(&p1, "Susan", "Pr", "Dev", 26);
    _c6_display_persion(&p1);
    _c6_deallocate_persion(&p1);

    c6_Persion *p2 = NULL;
    _c6_initialize_persion(&p2, "Mama", "Apt", "M2", 33);
    _c6_display_persion(&p2);
    _c6_deallocate_persion(&p2);
}


void c6_run() {
    c6_ex1();
}