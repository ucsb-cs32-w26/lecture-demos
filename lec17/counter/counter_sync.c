#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex;

volatile int counter = 0; 
int loops;

void *worker(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
	    pthread_mutex_lock(&mutex);
        counter++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc != 2) { 
        fprintf(stderr, "usage: threads <loops>\n"); 
        exit(1); 
    } 
    loops = atoi(argv[1]);
    printf("Initial value : %d\n", counter);
    
    pthread_t t1, t2;

    pthread_mutex_init(&mutex, NULL); //initialize the mutex

    pthread_create(&t1, NULL, worker, NULL); 
    pthread_create(&t2, NULL, worker, NULL);
    
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&mutex); //destroy (free) the mutex
    
    printf("Final value   : %d\n", counter);
    return 0;
}

