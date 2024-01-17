#include<pthread.h>
#include<semaphore.h>
#include<stdio.h>

#define BUFFER_SIZE 10
int buffer [ BUFFER_SIZE ] ;
int idx = 0; // Current element in buffer

pthread_mutex_t lock;
sem_t fill, empty;

_Atomic int _prod = 1;

void initialize() {
  pthread_mutex_init(&lock, NULL);
  sem_init(&fill, 0, 0);
  sem_init(&empty, 0, BUFFER_SIZE);
}

void *producer_thread(void *arg) {
  while(1) {
    int item = _prod++;

    sem_wait(&empty);
    pthread_mutex_lock(&lock);
    printf("produced: %d\n", item);

    buffer[idx++] = item;

    pthread_mutex_unlock(&lock);
    sem_post(&fill);

    if(item == 100) break;
  }
  return NULL;
}

void *consumer_thread(void *arg) {
  while(1) {

    sem_wait(&fill);
    pthread_mutex_lock(&lock);

    int item = buffer[--idx];

    pthread_mutex_unlock(&lock);
    sem_post(&empty);

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
