// array of producers, array of consumers, and array buffer ✔️
// producers can only produce if there's a space in the buffer and 's somthconsumers can only consume if thereing in the buffer.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFFER_SIZE 5
#define PRODUCERS_SIZE 5
#define CONSUMERS_SIZE 5

int buffer_count = -1;
int data = 0;
int flag = 0;

int buffer[BUFFER_SIZE];

pthread_mutex_t mutex;
pthread_cond_t cond;

void* produce(void* args){
    if(buffer_count < 4){
        pthread_mutex_lock(&mutex);
        data++;
        flag = 1;
        buffer_count++;
        printf("data produced at buffer location: %d\n", buffer_count);
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

void* consume(void * args){
    if(buffer_count > -1){
        pthread_mutex_lock(&mutex);
        while(flag == 0){
            printf("waiting\n");
            pthread_cond_wait(&cond, &mutex);
        }
        data--;
        printf("data consumed from buffer location: %d\n", buffer_count);
        buffer_count--;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(){
    pthread_t producers[PRODUCERS_SIZE], consumers[CONSUMERS_SIZE];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    for(int i = 0; i < PRODUCERS_SIZE; i++){
        pthread_create(&producers[i], NULL, produce, NULL);
    }
    
    for(int i = 0; i < CONSUMERS_SIZE; i++){
        pthread_create(&consumers[i], NULL, consume, NULL);
    }

    for(int i = 0; i < PRODUCERS_SIZE; i++){
        pthread_join(producers[i], NULL);
    }
    
    for(int i = 0; i < CONSUMERS_SIZE; i++){
        pthread_join(consumers[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&mutex);

    return 0;
}