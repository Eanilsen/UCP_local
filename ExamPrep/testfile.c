#include <stdio.h>
#include <stdlib.h>

typedef struct Lambda {
    struct Lambda *mu[3];
} Nu;

int main(int argc, char *argv[])
{
    Nu *n1 = (Nu*)malloc(sizeof(Nu));
    Nu *n2 = malloc(sizeof(Nu));

    n1->mu[0] = n2;
    return 0;
}
