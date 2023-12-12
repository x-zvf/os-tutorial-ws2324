#include <inttypes.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

void *do_something(void *data) {
  //int thread_id = ((thread_data *)data)->thread_id;
  int thread_id = (int)data;
  printf("Hello from thread %" PRIdPTR "\n", thread_id);
  pthread_exit(NULL);
}

int main(void) {

  pthread_t threads[NUM_THREADS];


  for (int i = 0; i < NUM_THREADS; i++) {
    int ret = pthread_create(&threads[i], NULL, do_something, i);
    if (ret) {
      printf("ERROR: pthread_create() returned %d\n", ret);
      exit(EXIT_FAILURE);
    }
  }

  for (int i = 0; i < NUM_THREADS; i++) {
    void *retval;
    pthread_join(threads[i], &retval);
  }
  return EXIT_SUCCESS;
}
