/* Imports the standard input/output library */
#include <stdio.h>

int main(void) {
    /* Variable declaration */
    int number;
    /* Takes user input and initializes var number */
    scanf("%d", &number);

    /* Conditional to check if var number is less than 0 or greater than 10 */
    if(number < 0 || number > 10) {
        /* Prints "Out of range" and new line to stdout */
        printf("Out of range\n");
    }
    /* Conditional to check in var number is not 5 */
    else if(number != 5) {
        /* Prints "Wrong" and new line to stdout */
        printf("Wrong\n");
    }
    /* Else clause for every other case */
    else {
        /* Prints "Correct" and new line to stdout */
        printf("Correct\n");
    }

    /* Returns 0 to signal end of program */
    return 0;
}
