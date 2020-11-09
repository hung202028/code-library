#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>


void* thread_run(void* arg)
{
    const char* message = (char*) arg;
    sleep(2);
    printf("%s : %s\n", "This is the message runnning from thread", message);
    return NULL;
}

void ex_01()
{
    pthread_t thread;

    void* data = "Thread_01";
    int err = pthread_create(&thread, NULL, thread_run, data);
    if (err) {
        printf("%s : %d\n", "Cannot create thread, error num", err);
        exit(1);
    }

    err = pthread_join(thread, NULL);
    if (err) {
        printf("%s : %d\n", "Cannot join thread, error num", err);
        exit(2);
    }
}

void ex_02()
{
    pthread_t thread;
    void* data = "Thread_02";
    int err = pthread_create(&thread, NULL, thread_run, data);
    if (err) {
        printf("%s : %d\n", "Cannot create thread, error num", err);
        exit(1);
    }

    err = pthread_detach(thread);
    if (err) {
        printf("%s : %d\n", "Cannot detach, error num", err);
        exit(2);
    }

    pthread_exit(NULL);
}

int main(int argc, char const *argv[])
{
    ex_01();
    printf("%s\n", "Hello world from main");
    return 0;
}