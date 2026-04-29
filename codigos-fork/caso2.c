#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void) {
    pid_t pid1, pid2;

    printf("Inicio (PID = %d)\n", getpid());

    pid1 = fork();   // primeiro fork

    pid2 = fork();   // segundo fork

    printf("Processo (PID = %d)\n", getpid());

    return 0;
}
