// Build (Linux/macOS):
// gcc -O2 -pthread -std=c11 -o smThreaded smThreaded.c
// -O2 sets optimization level to 2
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void scalarMultiplySequential(int *arr, int n, int scalar) {
    for (int i = 0; i < n; i++) {
        arr[i] *= scalar;
    }
}

typedef struct {
    int *arr;
    int n;
    int scalar;
    int threadId;
    int nthreads;
} ThreadArgs;

void* scalarMultiply(void *arg) {
    ThreadArgs *a = (ThreadArgs*)arg;

    int n = a->n;
    int chunkSize = n / a->nthreads;
    int start = a->threadId * chunkSize;
    int end = (a->threadId == a->nthreads - 1) ? n : (start + chunkSize);

    for (int i = start; i < end; i++) {
        a->arr[i] *= a->scalar;
    }

    return NULL;
}

int imin(int x, int y) { return (x < y) ? x : y; }
int imax(int x, int y) { return (x > y) ? x : y; }

void printArrayFirstLast10(const int *arr, int n) {
    printf("First 10 elements: ");
    for (int i = 0; i < imin(10, n); i++) {
        printf("%d ", arr[i]);
    }

    printf("\nLast 10 elements: ");
    for (int i = imax(0, n - 10); i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

double now_seconds(void) {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);

    return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <array_size> <number_of_threads>\n", argv[0]);
        return 1;
    }

    int size = (int)strtol(argv[1], NULL, 10);
    int nthreads = (int)strtol(argv[2], NULL, 10);

    if (nthreads < 1) {
        fprintf(stderr, "Error: Number of threads must be at least 1\n");
        return 1;
    }

    int scalar = 3;

    int *arr = malloc(size * sizeof(int));
    if (!arr) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = 1;
    }

    printf("Original array (first and last 10 elements):\n");
    printArrayFirstLast10(arr, size);

    double start1 = now_seconds();
    scalarMultiplySequential(arr, size, scalar);
    double end1 = now_seconds();

    printf("After scalar mult (sequential). first and last 10 elements:\n");
    printArrayFirstLast10(arr, size);

    printf("Execution time (seq): %.6f seconds\n", end1 - start1);

    // reset array
    for (int i = 0; i < size; i++) {
        arr[i] = 1;
    }

    pthread_t *threads = malloc(nthreads * sizeof(pthread_t));
    ThreadArgs *args = malloc(nthreads * sizeof(ThreadArgs));

    double start2 = now_seconds();

    for (int i = 0; i < nthreads; i++) {

        args[i].arr = arr;
        args[i].n = size;
        args[i].scalar = scalar;
        args[i].threadId = i;
        args[i].nthreads = nthreads;

        pthread_create(&threads[i], NULL, scalarMultiply, &args[i]);
    }

    for (int i = 0; i < nthreads; i++) {
        pthread_join(threads[i], NULL);
    }

    double end2 = now_seconds();

    printf("After scalar mult (parallel). first and last 10 elements:\n");
    printArrayFirstLast10(arr, size);

    printf("Execution time (parallel): %.6f seconds\n", end2 - start2);

    free(arr);
    free(threads);
    free(args);

    return 0;
}