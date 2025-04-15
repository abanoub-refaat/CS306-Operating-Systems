#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

// reader - writeres

int data = 0;
int reader_count = 0;
int flag = 0;
pthread_mutex_t mutex;
sem_t sem;

void* reader(void* args){
    pthread_mutex_lock(&mutex);
    reader_count++;
    if(reader_count == 1){
        sem_wait(&sem);
    }
    pthread_mutex_unlock(&mutex);
    printf("data read %d\n", data);

    pthread_mutex_lock(&mutex);
    reader_count--;
    if(reader_count == 0){
        sem_post(&sem);
    }
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* writer(void * args){
    sem_wait(&sem);
    data++;
    printf("data written\n");
    sem_post(&sem);
    return NULL;
}

int main(){
    pthread_t readers[5], writers[2];

    pthread_mutex_init(&mutex, NULL);
    sem_init(&sem, 0, 1);

    for(int i = 0; i < 5; i++){
        pthread_create(&readers[i], NULL, reader, NULL);
    }

    for(int i = 0; i < 2; i++){
        pthread_create(&writers[i], NULL, writer, NULL);
    }

    for(int i = 0; i < 2; i++){
        pthread_join(writers[i], NULL);
    }

    for(int i = 0; i < 5; i++){
        pthread_join(readers[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    return 0;
}