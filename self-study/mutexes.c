#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

/*
Mutexes: mutual exclusion (ensures that only one thread can access a resource at a time.)
Race Condition: a resource is being accessed by more than on thread in the same time.
Semaphores: used to control access to a resource by multiple threads. (more general than a mutex)
*/


// initalize a mutex
pthread_mutex_t mutex;
int value = 0;

void* method (void* args){
    for(int i = 0; i < 1000; i++){
        pthread_mutex_lock(&mutex);
        value++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(){

    pthread_t thread[5];
    pthread_mutex_init(&mutex,NULL);

    for(int i = 0; i < 5; i++){
        pthread_create(&thread[i],NULL,method,NULL);
    }

    for(int i = 0; i < 5; i++){
        pthread_join(thread[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    printf("the value after increament is: %d", value);

    return 0;
}