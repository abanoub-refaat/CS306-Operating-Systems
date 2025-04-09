#include <stdio.h>
#include <pthread.h>
#include <stdlib.h> // to use malloc() function.

// race condition: a resource is being accessed by more than on thread in the same time.
// will solve it using the lock condition. (mutex).
int x = 0;

// semphore: 

pthread_mutex_t mutex;

void *method(void *args){
    for(int i = 0; i < 100; i++){
        pthread_mutex_lock(&mutex);
        x++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t thread[5];
    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < 5; i++){
        pthread_create(&thread[i], NULL, method, NULL);
    }
    
    for(int i = 0; i < 5; i++){
        pthread_join(thread[i], NULL);
    }

    printf("x after the program is done: %d\n",x);
    pthread_mutex_destroy(&mutex);
    return 0;
}