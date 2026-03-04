#include <stdio.h>
#include <pthread.h>

/* 
Thread function 
- has to be exactly of this function signature
*/
void *hello_world_func(void *arg) {
    /* 
    We know the argument is a pointer to an int, so we cast it from a
    generic (void *) to a (int *), and then to an int. 
    */
    int id = *(int*)arg;
    printf("Hello world! I am thread %d\n", id);
    return NULL;
}

int main() {
    /*
    at this point, there's only a single thread in execution:
    the thread which runs main()
    */
    printf("[Main] Started main function!\n");

    pthread_t t;
    int id = 1;

    /*
    create the new thread using pthread_create
    
    int pthread_create(
        pthread_t *thread,              --> the thread object
        const pthread_attr_t *attr,     --> any attributes for your thread, usually set to NULL
        void *(*start_routine)(void *), --> pointer to the function that the thread runs
        void *arg                       --> any arguments to the function
    );
    */
    pthread_create(&t, NULL, hello_world_func, &id);

    /*
    the above call creates a new thread which is now ready to execute.
    it's up to the OS to decide which thread to give the CPU to: main or t,
    (or some other thread on your machine)
    */
    printf("[Main] Created thread t\n");

    /*
    pthread_join makes the calling thread (main) wait until thread t finishes
    */
    pthread_join(t, NULL);

    /*
    at this point, the thread t has finished execution, and the OS wakes up
    the main thread and it continues execution
    */
    printf("[Main] thread t joined. Finishing program.\n");

    return 0;
}