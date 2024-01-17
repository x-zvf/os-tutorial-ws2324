#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

#define BUFFER_SIZE 10
int buffer [ BUFFER_SIZE ] ;
int idx = 0; // Current element in buffer

pthread_mutex_t lock;
//name these to something useful
sem_t a,b;

_Atomic int _prod = 1;

void initialize() {
  pthread_mutex_init(&lock, NULL);
  sem_init(&fill, 0, 0);
  sem_init(&empty, 0, BUFFER_SIZE);
}

void *producer_thread(void *arg) {
  while(1) {
    int item = _prod++;

    // something something

    printf("produced: %d\n", item);

    buffer[idx++] = item;

    // something something

    if(item == 100) break;
  }
  return NULL;
}

void *consumer_thread(void *arg) {
  while(1) {

    // something something


    int item = buffer[--idx];

    // something something

    printf("consumed: %d\n", item);
    if(item == 100) break;
  }
  return NULL;
}



int main(void) {
  initialize();
  pthread_t t1, t2;
  pthread_create(&t1, NULL, producer_thread, NULL);
  pthread_create(&t2, NULL, consumer_thread, NULL);
  pthread_join(t1, NULL);
  pthread_join(t2, NULL);
}
