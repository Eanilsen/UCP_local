/**
 * question4.c - Worksheet4
 *
 * @author		Even A. Nilsen
 * @version		20.09.2016
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "question4.h"
#define TRUE 1

int main(int argc, char *argv[])
{
    int *intArray = (int*)malloc(argc * sizeof(int));
    int result = 0;

    if (argc < 3) {
        printf("Not enough arguments. The program takes 2 or more arguments.\n");
        return 1;
    }
    else {
        string_to_integer(intArray, argc, argv);

        if (isEqual(argv[1], "sum") == 1) {
            result = sum(intArray, argc-2);
            printf("%d\n", result);
        }
        else if (isEqual(argv[1], "max") == 1) {
            result = max(intArray, argc-2);
            printf("%d\n", result);
        }
        else if (isEqual(argv[1], "reverse") == 1) {
            int index = argc-3;
            reverse(intArray, index);
            print_array(intArray, argc-2);
        }
        else {
            printf("First argument must be \"sum\", \"max\" or \"reverse\".\n");
            return 1;
        }
    }
    return 0;
}

/**
 * Wrapper for strcmp, returns 1 if true and 0 if false
 * @param *str1 string to compare
 * @param *str2 string to compare
 * @return TRUE
 * @return !TRUE
 */
int isEqual(char *str1, char *str2)
{
    int equal = strcmp(str1, str2);

    if (equal == 0) {
        return TRUE;
    }
    else {
        return !TRUE;
    }
}

/**
 * Wrapper for string_to_int, offputs argv to exclude first two indexes
 * @param intArray[] array to fill
 * @param args number of command line arguments
 * @param *argv[] command line arguments
 */
void string_to_integer(int intArray[], int args, char *argv[])
{
    char **chArray = (char**)malloc(args * sizeof(char));
    int i;

    for (i = 2; i < args; i++) {
        chArray[i-2] = argv[i];
    }

    string_to_int(chArray, intArray, args-2);
}
