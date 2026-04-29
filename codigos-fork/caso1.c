#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid;

    printf("Antes do fork (PID = %d)\n", getpid());

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        printf("Filho: PID = %d, Pai = %d\n", getpid(), getppid());
    } else {
        printf("Pai:  PID = %d, Filho = %d\n", getpid(), pid);
    }

    printf("Fim (PID = %d)\n", getpid());

    return 0;
}
