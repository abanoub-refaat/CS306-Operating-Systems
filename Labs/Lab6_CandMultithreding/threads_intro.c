#include <stdio.h>
#include <pthread.h>

void *method(void *args)
{
    printf("Here in the method!\n");
    return NULL;
}

int main()
{

    pthread_t thread; // declare a thread

    // identifire, attribute, method, return type of the method
    if (pthread_create(&thread, NULL, method, NULL) != 0)
    {
        printf("Error\n");
        return 1;
    }

    printf("Before the join\n");
    pthread_join(thread, NULL); // wait for the thread to finish
    printf("After the join\n");
    return 0;
}