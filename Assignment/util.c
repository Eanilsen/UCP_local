/**
 * util.c - Utility functions
 *
 * @author		Even A. Nilsen
 * @version		20.10.2016
 */
#include <stdio.h>
#include <string.h>
#include "util.h"
#define TRUE 1
#define FALSE !TRUE

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

    if (equal == 0)
    {
        return TRUE;
    }
    else
    {
        return !TRUE;
    }
}
