// this calls exec without a fork
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *path_to_executable_file = "./hello";
    char *argv[] = { "hello", "5", NULL };

    execvp(path_to_executable_file, argv);

    /* Only reached if execvp fails */
    perror("execvp");
    
    printf("this line will never get executed unless exec fails");
    return 1;
}