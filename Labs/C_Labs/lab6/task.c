#include <stdio.h>
#include <pthread.h>

struct pair
{
    int x;
    int y;
} p1;

void *method(void *args)
{
    struct pair *p1 = (struct pair *)args;
    printf("Here in the method x = %d, and y = %d\n", (*p1).x, (*p1).y);
    return NULL;
}

int main()
{
    pthread_t thread;

    p1.x = 3;
    p1.y = 5;

    if (pthread_create(&thread, NULL, method, &p1) != 0)
    {
        printf("Error\n");
        return 1;
    }

    pthread_join(thread, NULL);
    return 0;
}