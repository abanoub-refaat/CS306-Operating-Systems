#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// Consumer - producer
int data = 0;
int flag = 0;
pthread_mutex_t mutex;
pthread_cond_t cond;

void* produce(void* args){
    pthread_mutex_lock(&mutex);
    data++;
    flag = 1;
    pthread_cond_signal(&cond);
    printf("data produced\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void* consume(void * args){
    pthread_mutex_lock(&mutex);
    while(flag == 0){
        printf("waiting\n");
        pthread_cond_wait(&cond, &mutex);
    }
    printf("data consumed %d\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(){
    pthread_t threads[2];

    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&threads[0], NULL, produce, NULL);
    pthread_create(&threads[1], NULL, consume, NULL);

    for(int i = 0; i < 2; i++){
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&mutex);
    return 0;
}