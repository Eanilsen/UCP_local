#include <stdio.h>

int main(int argc, char *argv[])
{
    int n = 1, var = 3, bit = 2;
    
    printf("%d\n", 1 << n);
    bit = var & 1;
    printf("%d\n", bit);

    return 0;
}
