// write a method that creates 5 threads to increament a global vaiable named "counter" initialzed with zero: such that it becomes 5000 and each thread increaments 1000.

#include <stdio.h>
#include <pthread.h>


int sum = 0;
pthread_mutex_t mutex;

void *method (void * args){
    for (int i = 0; i < 1000; i++){
        pthread_mutex_lock(&mutex);
        sum++;
        pthread_mutex_unlock(&mutex);
    }
}

int main(){
    pthread_t thread[5];
    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < 5; i++){
        pthread_create(&thread[i], NULL, method, NULL);
    }

    for(int i = 0; i < 5; i++){
        pthread_join(thread[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    printf("The sum after the execution is: %d\n", sum);
    return 0;
}