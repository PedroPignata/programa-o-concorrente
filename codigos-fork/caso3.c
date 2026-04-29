
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid;

    printf("A (PID = %d)\n", getpid());

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    }

    if (pid == 0) {
        // Código do filho
        printf("B (Filho: PID = %d, Pai = %d)\n", getpid(), getppid());
        pid = fork();
        printf("C (PID = %d)\n", getpid());
    } else {
        // Código do pai
        printf("D (Pai: PID = %d, Filho = %d)\n", getpid(), pid);
    }

    printf("E (PID = %d)\n", getpid());

    return 0;
}

