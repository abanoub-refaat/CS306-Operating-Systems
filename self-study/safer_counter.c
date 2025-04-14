#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

// initialize both a mutex and a semaphore.
pthread_mutex_t mutex;
sem_t sem;

int shared_counter = 0;

void* method (void* args){
    for(int i = 0; i < 100; i++){
        sem_wait(&sem);
        pthread_mutex_lock(&mutex);
        shared_counter++;
        pthread_mutex_unlock(&mutex);
        sem_post(&sem);
    }
}

int main(){
    pthread_t thread[6];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem, 0, 3); // max three threads allowed.

    for(int t = 0; t < 6; t++){
        pthread_create(&thread[t],NULL, method, NULL);
    }

    for(int t = 0; t < 6; t++){
        pthread_join(thread[t], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&sem);

    printf("The value of the shared counter is: %d", shared_counter);

    return 0;
}