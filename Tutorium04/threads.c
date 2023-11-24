#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#define NUM_THREADS 5


struct thread_data {
    int thread_id;
    char *message;
};

void *do_something(void *data) {
    int thread_id = ((struct thread_data *)data)->thread_id;
    printf("Hello from thread %" PRIdPTR "\n", thread_id);
    pthread_exit(NULL);
}

int main(void) {

    pthread_t threads[NUM_THREADS];
    struct thread_data td[NUM_THREADS];

    for(int i = 0; i < NUM_THREADS; i++) {
        td[i].thread_id = i;
        int ret = pthread_create(&threads[i], NULL, do_something, &td[i]);
        if(ret) {
            printf("ERROR: pthread_create() returned %d\n", ret);
            exit(EXIT_FAILURE);
        }
    }

    for(int i = 0; i < NUM_THREADS; i++) {
        void *retval;
        pthread_join(threads[i], &retval);

    }
    return EXIT_SUCCESS;
}
