#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/* Thread function */
void *hello_world_func(void *arg) {
    int id = *(int*)arg;
    printf("Hello world! I am thread %d\n", id);
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s <n>\n", argv[0]);
        fprintf(stderr, "where <n> is the number of threads\n");
        return 1;
    }

    printf("[Main] Started main function!\n");

    int nthreads = atoi(argv[1]);   // convert command line argument

    /* Allocate arrays for threads */
    pthread_t *threads = malloc(nthreads * sizeof(pthread_t));
    
    /* allocate arrays of ids for our hello_world_func */
    int *ids = malloc(nthreads * sizeof(int));  

    /* Create all the threads */
    for (int i = 0; i < nthreads; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, hello_world_func, &ids[i]);
    }

    /*
    important: never assume the order in which the threads will be executed.
    they may be executed in any order that the OS chooses.
    pthread_create only creates the thread and puts it in "Ready" state for 
    the OS to execute.
    */
    printf("[Main] Created n threads\n");

    /* Join all the threads */
    for (int i = 0; i < nthreads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("[Main] all threads joined. Finishing program.\n");

    free(threads);
    free(ids);

    return 0;
}