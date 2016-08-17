#include <stdio.h>

/* readInt function declaration
 * @return result
 */
int readInt(void) {
    /* Declaration of var result */
    int result;
    /* Prints "Enter an integer" to stdout added ": " for prettier output */
    printf("Enter an integer: ");
    /* Takes input from stdin and initialiezes var result */
    scanf("%d", &result);
    /* Returns value of var result */
    return result;
}

/* printInt function declaration. Data type void means it does not return a
 * value
 * @param x Integer to print
 */
void printInt(int x) {
    /* Prints "The result is: " to stdout */
    printf("The result is: ");
    /* Appends the previous print with var x */
    printf("%d", x);
}

/* Main function declaration */
int main(void) {
    /* Variable declarations */
    int a, b, c;
    /* Calls function readInt() and initializes var a with return value */
    a = readInt();
    /* Same as above */
    b = readInt();
    /* Initialization of var c */
    c = (a + b) * (a - b);
    /* Function call to function printInt(int x) taking var c as an argument */
    printInt(c);
    /* Returns 0 to signal end of program */
    return 0;
}
