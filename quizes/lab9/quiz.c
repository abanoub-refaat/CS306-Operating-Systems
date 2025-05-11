#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <string.h>

#define MAX_CARS 5

char* names[MAX_CARS] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};

int currently_parked_cars = 0;

typedef struct {
    int car_id;
    char owner_name[20];
    int stay_time;
    float bill_amount;
} CarInfo;

sem_t sem;
pthread_mutex_t mutex;

void* park(void *args) {
    CarInfo *info = (CarInfo *)args;

    sem_wait(&sem);

    pthread_mutex_lock(&mutex);
    printf("Car %d (%s) is trying to park ...\n", info->car_id, info->owner_name);
    currently_parked_cars++;
    pthread_mutex_unlock(&mutex);

    pthread_mutex_lock(&mutex);
    printf("Car %d (%s) has parked. Currently parked: %d\n", info->car_id, info->owner_name, currently_parked_cars);
    pthread_mutex_unlock(&mutex);

    sleep(info->stay_time);

    pthread_mutex_lock(&mutex);
    currently_parked_cars--;
    printf("Car %d (%s) is leaving... Currently parked: %d\n", info->car_id, info->owner_name, currently_parked_cars);
    info->bill_amount = info->stay_time * 5.0;
    pthread_mutex_unlock(&mutex);

    sem_post(&sem);
    return (void*)info;
}

int main() {
    pthread_t cars[MAX_CARS];
    CarInfo* infos[MAX_CARS];

    sem_init(&sem, 0, 1);
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < MAX_CARS; i++) {
        infos[i] = malloc(sizeof(CarInfo));
        infos[i]->car_id = i + 1;
        strcpy(infos[i]->owner_name, names[i]);
        infos[i]->stay_time = 3;
        infos[i]->bill_amount = 0;
        pthread_create(&cars[i], NULL, park, infos[i]);
    }

    for (int i = 0; i < MAX_CARS; i++) {
        CarInfo *result;
        pthread_join(cars[i], (void**)&result);
        printf("Car %d (%s): Bill = %.2f\n", result->car_id, result->owner_name, result->bill_amount);
        free(result);
    }

    sem_destroy(&sem);
    pthread_mutex_destroy(&mutex);

    return 0;
}
