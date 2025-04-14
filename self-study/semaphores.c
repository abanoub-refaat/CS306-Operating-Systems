#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

/*
Mutexes: mutual exclusion (ensures that only one thread can access a resource at a time.)
Race Condition: a resource is being accessed by more than on thread in the same time.
Semaphores: used to control access to a resource by multiple threads. (more general than a mutex)
*/


// initalize a semaphore
sem_t sem;
int value = 0;

void* enterRoom (void* args){
    int id = * (int*) args;

    free(args);

    sem_wait(&sem);

    printf("thread %d enters at the room\n", id);
    sleep(2);
    printf("Thread %d leaving the room\n", id);

    sem_post(&sem);
}

int main(){

    pthread_t thread[6];
    int ids[6];

    
    sem_init(&sem,0, 3); // allow up to only 3 threads.
    
    for(int i = 0; i < 6; i++){
        int* tid = malloc(sizeof(int));
        *tid = i + 1;
        pthread_create(&thread[i],NULL,enterRoom,tid);
    }

    for(int i = 0; i < 6; i++){
        pthread_join(thread[i], NULL);
    }

    sem_destroy(&sem);
    return 0;
}