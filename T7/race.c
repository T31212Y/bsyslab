#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 3
#define ITERATIONS 10000000

static volatile int counter = 0;
void *worker(void *arg) {
    for (int i = 0; i < ITERATIONS; i++) {
        counter = counter + 1;
    }
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, worker, NULL) != 0)
            return 1;
    }
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0)
            return 1;
    }
    printf("Counter: %d\n", counter);
    return 0;
}
