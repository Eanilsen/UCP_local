/**
 * question3.c - Worksheet4
 *
 * @author		Even A. Nilsen
 * @version		21.09.2016
 */
#include <stdio.h>
#include "question3.h"

/**
 * Outputs an array of ints on a single line with comma delimiters
 * @param intArray[] array to output
 * @param length length of array
 */
void print_array(int intArray[], int length)
{
    int i;
    for (i = 0; i < length; i++) {
        if (i == 0) {
            printf("{%d, ", intArray[i]);
        }
        else if (i == length-1) {
            printf("%d}\n", intArray[i]);
        }
        else {
            printf("%d, ", intArray[i]);
        }
    }
}
