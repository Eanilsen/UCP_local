#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "testfile.h"

int main(int argc, char *argv[])
{
    time_t startTime = time(NULL);
    int i;
    srand(startTime);

    for (i = 0; i < 10; i++)
    {
        rand_int(startTime);
    }

    return 0;
}

void rand_int(time_t seed)
{
    int random;
    random = (rand() % 100) + 1;
    if (random < 50)
    {
        printf("Not so random\n");
    }
    else
    {
        printf("%d\n", (rand() % 100) + 1);
    }
}
