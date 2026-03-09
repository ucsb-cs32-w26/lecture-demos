#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t lock;

void *buy_ticket(void *arg) {
    int *tickets = (int*) arg;

    pthread_mutex_lock(&lock);
    if (*tickets > 0) {
        (*tickets)--;
        printf("SUCCESS: bought a ticket!\n");
    } else {
        printf("FAILURE: ticket sold out.\n");
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    int tickets = 1;

    pthread_t t1, t2;

    pthread_create(&t1, NULL, buy_ticket, &tickets);
    pthread_create(&t2, NULL, buy_ticket, &tickets);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Final Tickets Remaining: %d\n", tickets);

    return 0;
}



