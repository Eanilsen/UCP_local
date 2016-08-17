/* Imports standard input/output library */
#include <stdio.h>

/* Main function declaration */
int main(void) {
    /* Declares variables count and i */
    int count, i;
    /* Takes user input and initializes var count */
    scanf("%d", &count);

    /* Initializes var i with int value 0 */
    i = 0;
    /* While loop that runs as long as var i is less than var count */
    while(i < count) {
        /* Prints var i to stdout */
        printf("%d ", i);
        /* Increments var i by one (i = i + 1) */
        i++;
    }

    /* Returns 0 to signal end of program */
    return 0;
}
