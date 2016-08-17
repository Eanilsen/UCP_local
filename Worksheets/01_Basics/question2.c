#include <stdio.h>

int take_input()
{
    int input;
    
    printf("%s", "Enter an integer: ");
    scanf("%d", &input);

    return input;
}

void is_divisible(int x, int y)
{
    if(x % y == 0)
    {
        printf("%s\n", "Divisible");
    }
    else
    {
        printf("%s\n", "Not divisible");
    }
}

int main(int argc, char *argv[])
{
    int first_num, second_num;

    printf("\n%s\n", "--------------------");
    first_num = take_input();
    second_num = take_input();
    is_divisible(first_num, second_num);
    printf("%s\n\n", "--------------------");
    return 0;
}
