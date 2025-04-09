// write a method that creates 5 threads to increament a global vaiable named "counter" initialzed with zero: such that it becomes 5000 and each thread increaments 1000.

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int sum = 0;
sem_t sem;

void *method (void * args){
    for (int i = 0; i < 1000; i++){
        sem_wait(&sem);
        sum++;
        sem_post(&sem);
    }
}

int main(){
    pthread_t thread[5];
    sem_init(&sem, 0, 1);

    for(int i = 0; i < 5; i++){
        pthread_create(&thread[i], NULL, method, NULL);
    }

    for(int i = 0; i < 5; i++){
        pthread_join(thread[i], NULL);
    }

    sem_destroy(&sem);

    printf("The sum after the execution is: %d\n", sum);
    return 0;
}