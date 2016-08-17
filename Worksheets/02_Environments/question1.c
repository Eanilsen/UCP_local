#include <stdio.h>

int power_of_two()
{
    static int n = 1;

    n *= 2;
    
    return n;
}

int main(int argc, char *argv[])
{
    int i;
    for (i = 0; i < 10; i++) {
        int x;
        x = power_of_two();
        printf("%d\n", x);
    }
    return 0;
}
