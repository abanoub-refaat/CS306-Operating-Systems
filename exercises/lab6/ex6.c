#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

// pthread_self: get the id of the current thread
//perror: print error

typedef struct {
    int start;
    int end;
    char *message;
} ThreadData;

void* method(void* args){
    ThreadData *data = (ThreadData *) args;
    for(int i = data -> start; i <= data -> end; i++){
        printf("Thread ID: %lu message: %s %d\n", (unsigned long)pthread_self, data -> message, i);
        sleep(1);
    }
    return NULL;
}

int main(){
    pthread_t thread_id;

    ThreadData data;
    data.start = 1;
    data.end = 5;
    data.message = "Welcome";

    if(pthread_create(&thread_id, NULL, method, &data) != 0){
        perror("Error creating the tread");
        return 1;
    }

    if(pthread_join(thread_id, NULL) != 0){
        perror("Faild to join threads");
        return 1;
    }

    printf("Main thread: All tasks are complete\n");
    return 0;
}