#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    pid_t pid;

    pid = fork();
    if (pid < 0) {
        fprintf(stderr, "%s\n", "Fork failed");
        return 1;
    }

    if (pid == 0) {
        printf("%s: \n", "Child process");
        execlp("/bin/ls", "ls", NULL);
    }
    else {
        wait(NULL);
        printf("%s\n", "Child process finished!");
    }

    return 0;
}
