#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

// race condition: a resource is being accessed by more than on thread in the same time.
// will solve it using the lock condition. (mutex).
int x = 0;

// semphore: 

sem_t sem;

void *method(void *args){
    for(int i = 0; i < 100; i++){
        //pthread_mutex_lock(&mutex);
        sem_wait(&sem);
        x++;
        //pthread_mutex_unlock(&mutex);
        sem_post(&sem);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t thread[5];
    sem_init(&sem, 0, 3);

    for(int i = 0; i < 5; i++){
        pthread_create(&thread[i], NULL, method, NULL);
    }
    
    for(int i = 0; i < 5; i++){
        pthread_join(thread[i], NULL);
    }

    sem_destroy(&sem);
    return 0;
}