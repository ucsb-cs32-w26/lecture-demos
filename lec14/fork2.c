#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    // anything here after fork -> run by both
    // return value for fork in parent process > 0
    // return value for fork in child process = 0
    if (pid == 0) {
        /* child process */
        while (1) {
            printf("I'm the child. PID = %d\n", getpid());
            fflush(stdout);   // ensure output appears immediately
            sleep(5);
        }
    } else if (pid > 0) {
        /* parent process */
        while (1) {
            printf("I'm the parent. PID = %d\n", getpid());
            fflush(stdout);
            sleep(5);
        }
    } else {
        /* fork failed */
        perror("fork failed");
        return 1;
    }

    return 0;
}