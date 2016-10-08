/**
 * question2.c - Worksheet4
 *
 * @author		Even A. Nilsen
 * @version		21.09.2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "question2.h"

/**
 * Converts an array of string-formatted integers into an array of ints
 * @param *chArray[] an array of string-formatted integers
 * @param intArray[] the new array of integers
 * @param length the length of the array
 */
void string_to_int(char *chArray[], int intArray[], int length)
{
    int i;
    for (i = 0; i < length; i++) {
        intArray[i] = atoi(chArray[i]);
    }
}

/**
 * Print every element of array of integers
 * @param intArray[] array of integers
 */
void print_all(int intArray[], int length)
{
    int i;
    for (i = 0; i < length; i++) {
        printf("%d", intArray[i]);
        printf("%c", ' ');
    }
    printf("\n");
}
