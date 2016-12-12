#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i;
    double **a, **b;
    double **c[3];
    double d[] = {2.0, 3.0, 5.0, 7.0, 11.0};

    a = (double**)malloc(3 * sizeof(double*));
    c[2] = (double**)malloc(2 * sizeof(double*));

    *c = a;
    *(c + 1) = a + 2;
    b = *(c + 2);

    a[0] = d;
    *(a + (int)*d) = d + 2;
    c[0][1] = &d[2];
    c[2][0] = a[1];
    c[(int)**a]++;
    c[2][0] = c[1][0] + 1;

    for (i = 0; i < 5; i++)
    {
        printf("%f\n", d[i]);
    }

    a[1][0] *= b[1][0];
    a[0][1] *= b[0][1];

    for (i = 0; i < 5; i++)
    {
        printf("%f\n", d[i]);
    }
    return 0;
}
