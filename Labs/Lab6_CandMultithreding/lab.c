#include <stdio.h>

// Forward declaraion for a function
int sum(int x, int y);

int main()
{
    int x = 0;
    int *pt = &x;
    printf("Hello, world\n");
    printf("Memory location of x is %p\n", pt);
    return 0;
}

int sum(int x, int y)
{
    return x + y;
}