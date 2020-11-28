#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdatomic.h>
#include <stdbool.h>
#include <pthread.h>

atomic_bool flag = ATOMIC_VAR_INIT(false);

void* f1(void* p)
{
    printf("%s\n", "F1 executed");
    sleep(1);
    atomic_store(&flag, true);
    return NULL;
}

void* f2(void* p)
{
    bool local_flag = false;

    while (!(local_flag = atomic_load(&flag))) {
        // do nothing while flag is false
    }

    printf("%s\n", "F2 executed");
    return NULL;
}


int main(int argc, char const *argv[])
{
    int rc = 1;
    pthread_t t1 = NULL;
    pthread_t t2 = NULL;

    rc = pthread_create(&t1, NULL, f1, NULL);
    if (rc != 0) {
        fprintf(stderr, "%s\n", "T1 failed\n");
        return EXIT_FAILURE;
    }

    rc = pthread_create(&t2, NULL, f2, NULL);
    if (rc != 0) {
        fprintf(stderr, "%s\n", "T2 failed\n");
        return EXIT_FAILURE;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    printf("%s\n", "T1 & T2 finished");

    return 0;
}