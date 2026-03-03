#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char *argv[]) {
    pid_t pid;
    int ret;
    char *child_argv[3];
    char *path_to_executable_file = "./hello";

    /* Arguments for execvp */
    child_argv[0] = "hello";  // argv[0] is program name (convention)
    child_argv[1] = "10";  // hello expects a cmd line arg count
    child_argv[2] = NULL;  // MUST end with NULL

    pid = fork();

    if (pid < 0) {
        /* fork failed */
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        /* child process */
        ret = execvp(path_to_executable_file, child_argv);

        /* execvp only returns on error */
        perror("execvp");
        exit(ret);
    }

    /* parent process */
    printf("Parent process (pid=%d) continues to execute\n", getpid());

    return 0;
}