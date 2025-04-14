// NOTES:
// echo %errorlevel% 
#include <stdio.h>
#include <pthread.h>

typedef struct {
    int x;
    float y;
} myType;

void *method(void *args){
    myType *type = (myType *) args;
    printf("Here in method%d\n", type -> x);
    printf("Here in method%d\n", type -> y);
    return NULL;
}

int main(){

    pthread_t thread[2];
    myType type = {1, 2};
    int ids[2];
    for(int i = 0; i < 2; i++){
        ids[i] = i + 1;
        pthread_create(&thread[i], NULL, method, &type);
    }
    
    for(int i = 0; i < 2; i++)
        pthread_join(thread[i], NULL);
    return 0;
}