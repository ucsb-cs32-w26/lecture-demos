#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // create a new child process
    pid = fork();

    // check and handle error return value
    if(pid == -1) {  
        perror("fork failed!\n");
        return 1;
    }

    // both parent and child execute this
    printf("pid = %d\n", pid);  

    return 0;
}
