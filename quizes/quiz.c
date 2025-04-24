#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define MAX_CARS 5

char* names[MAX_CARS] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};


int currently_parked_cars;

typedef struct {
    int car_id;
    char owner_name[20];
    int stay_time;
    float bill_amount;
} CarInfo;

sem_t sem;
pthread_mutex_t mutex;

void* park(void * args){
    CarInfo *info = (CarInfo *) args;
    sem_wait(&sem);

    pthread_mutex_lock(&mutex);
    printf("Car %d (%s) is trying to park ...\n", info->car_id, names[info->car_id -1]);
    currently_parked_cars++;
    pthread_mutex_unlock(&mutex);

    pthread_mutex_lock(&mutex);
    printf("Car %d (%s) has parked. Currently parked: %d\n", info->car_id, names[info->car_id -1], currently_parked_cars);
    sleep(info->stay_time);
    pthread_mutex_unlock(&mutex);
    
    pthread_mutex_lock(&mutex);
    currently_parked_cars--;
    printf("Car %d (%s) is leaving... Currently parked: %d\n", info->car_id, names[info->car_id -1], currently_parked_cars);
    info->bill_amount = info->stay_time* 5.0;
    pthread_mutex_unlock(&mutex);

    sem_post(&sem);
    return (void**)info;
}

int main(){
    pthread_t cars[5];
    CarInfo info;
    CarInfo answer;
    sem_init(&sem, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    for(int i = 0; i < MAX_CARS; i++){
        info.bill_amount = 0;
        info.car_id = i + 1;
        strcpy(info.owner_name, names[i]);
        info.stay_time = 3;
        pthread_create(&cars[i], NULL, park, &info);
    }

    for(int i = 0; i < MAX_CARS; i++){
        pthread_join(cars[i], (CarInfo**)info);
        printf("Car %d (%s): Bill = %d",info.car_id,info.bill_amount);
    }

    sem_destroy(&sem);
    pthread_mutex_destroy(&mutex);

    return 0;
}