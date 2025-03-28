#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *computation1(void *props);
void *computation2(void *props);

struct props
{
    int *arr;
    int number;
};

int main(int argc, char *argv[])
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *t_sum1, *t_sum2;
    struct props props;

    pthread_t thread1;
    pthread_t thread2;

    props.arr = arr;
    props.number = 10;

    pthread_create(&thread1, NULL, computation1, (void *)&props);
    pthread_create(&thread2, NULL, computation2, (void *)&props);

    pthread_join(thread1, (void **)&t_sum1);
    pthread_join(thread2, (void **)&t_sum2);

    printf("The total sum is: %d\n", *t_sum1 + *t_sum2);

    free(t_sum1);
    free(t_sum2);
    return 0;
}

void *computation1(void *props)
{
    struct props *p = (struct props *)props;
    int *a = (*p).arr;
    int n = (*p).number;
    int *sum = malloc(sizeof(int));
    *sum = 0;

    for (int i = 0; i < n / 2; i++)
    {
        *sum += *(a + i);
    }

    printf("The sum computed by thread 1 is: %d\n", *sum);
    pthread_exit(sum);
}

void *computation2(void *props)
{
    struct props *p = (struct props *)props;
    int *a = p->arr;
    int n = p->number;
    int *sum = malloc(sizeof(int));
    *sum = 0;

    for (int i = n / 2; i < n; i++)
    {
        *sum += *(a + i);
    }

    printf("The sum computed by thread 2 is: %d\n", *sum);
    pthread_exit(sum);
}
