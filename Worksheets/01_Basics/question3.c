#include <stdio.h>

int factorial(int n);

int main(void)
{
    int input, result;

    while(1)
    {
        printf("%s", "Enter a positive integer or a negative integer to exit: ");
        scanf("%d", &input);

        if (input >= 0) {
            result = factorial(input);
            printf("%d\n", result);
        }
        else
        {
            break;
        }
    }

    return 0;
}

int factorial(int n)
{
   int i, result = 1;
   
   for (i = 2; i <= n; ++i) {
       result *= i;
   }
   
   return result;
}
