#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void loadedDie(int *a, int *b)
{
    static int count = 0;

    if (count % 2 == 0)
    {
        *a = 6;
        *b = 6;
        count++;
    }
    else
    {
        *a = (rand() % 6) + 1;
        *b = (rand() % 6) + 1;
        count++;
    }
}

int main(int argc, char *argv[])
{
    int a = 1, b = 2, i;
    int *aPtr = NULL, *bPtr = NULL;
    aPtr = &a;
    bPtr = &b;

    srand(time(NULL));
    printf("a:%d b:%d\n", a, b);

    for (i = 0; i < 10; i++)
    {
        loadedDie(aPtr, bPtr);
        printf("a:%d b:%d\n", a, b);
    }
    
    return 0;
}
