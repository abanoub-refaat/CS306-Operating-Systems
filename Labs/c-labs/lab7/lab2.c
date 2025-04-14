#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

// race condition: a resource is being accessed by more than on thread in the same time.
// will solve it using the lock condition. (mutex). in lab3
int x = 0;
void *method(void *args){
    for(int i = 0; i < 100; i++)
        x++;
    return NULL;
}

int main(int argc, char *argv[]) {
    pthread_t thread[5];

    for(int i = 0; i < 5; i++){
        pthread_create(&thread[i], NULL, method, NULL);
    }
    
    for(int i = 0; i < 5; i++){
        pthread_join(thread[i], NULL);
    }

    return 0;
}