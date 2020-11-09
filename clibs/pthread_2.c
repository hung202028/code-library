#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0

typedef unsigned int bool_t;

typedef struct _t {
    bool_t          done;
    pthread_mutex_t mtx;
    pthread_cond_t  cv;
} shared_state_t;

void share_state_init(shared_state_t *ss)
{
    ss->done = FALSE;
    pthread_mutex_init(&ss->mtx, NULL);
    pthread_cond_init(&ss->cv, NULL);
}

void share_state_destroy(shared_state_t *ss)
{
    pthread_mutex_destroy(&ss->mtx);
    pthread_cond_destroy(&ss->cv);
}

void* thread1_run(void *arg)
{
    shared_state_t* ss = (shared_state_t*) arg;
    pthread_mutex_lock(&ss->mtx);
    printf("%s\n", "A");
    sleep(1);
    ss->done = TRUE;
    pthread_cond_signal(&ss->cv);
    pthread_mutex_unlock(&ss->mtx);
    return NULL;
}

void* thread2_run(void* arg)
{
    shared_state_t *ss = (shared_state_t*) arg;
    pthread_mutex_lock(&ss->mtx);
    while (!ss->done) {
        pthread_cond_wait(&ss->cv, &ss->mtx);
    }
    printf("%s\n", "B");
    pthread_mutex_unlock(&ss->mtx);
    return NULL;
}

void ex1()
{
    shared_state_t ss;
    share_state_init(&ss);

    pthread_t thread_1;
    pthread_t thread_2;

    int err_1 = pthread_create(&thread_1, NULL, thread1_run, &ss);
    if (err_1) {
        printf("%s : %d\n", "Thread 1 cannot created", err_1);
        exit(1);
    }

    int err_2 = pthread_create(&thread_2, NULL, thread2_run, &ss);
    if (err_2) {
        printf("%s : %d\n", "Thread 1 cannot created", err_2);
        exit(1);
    }

    err_1 = pthread_join(thread_1, NULL);
    err_2 = pthread_join(thread_2, NULL);

    if (err_1 || err_2) {
        printf("%s\n", "Cannot join threads");
        exit(2);
    }

    share_state_destroy(&ss);
}

int main(int argc, char const *argv[])
{
    while (TRUE) {
        ex1();
        sleep(1);
    }
    return 0;
}









