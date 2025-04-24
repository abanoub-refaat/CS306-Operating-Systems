#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// dining philosophers problem

sem_t sem[5];

void* eat(void * args){
    int *id = (int *) args;
    int left = *id;
    int right = (left + 1) % 5;
    sem_wait(&sem[left]);
    sem_wait(&sem[right]);

    printf("thinking %d\n", *id);
    printf("eating %d\n", *id);

    sem_post(&sem[left]);
    sem_post(&sem[right]);
    return NULL;
}

int main(){
    pthread_t philosophers[5];
    int ids[5];

    for(int i =0; i < 5; i++){
        sem_init(&sem[i],0,1 );
    }

    for (int i = 0; i < 5; i++)
    {
        ids[i]=i+1;
    }
    
    for(int i = 0; i < 5; i++){
        pthread_create(&philosophers[i], NULL, eat, &ids[i]);
    }

    for(int i = 0; i < 5; i++){
        pthread_join(philosophers[i], NULL);
    }

    for(int i = 0; i < 5; i++){
        sem_destroy(&sem[i]);
    }
    return 0;
}