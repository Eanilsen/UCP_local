/**
 * util.c - Utility functions
 *
 * @author		Even A. Nilsen
 * @version		20.10.2016
 */
#include <stdio.h>
#include <stdlib.h>
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
        return FALSE;
    }
}

/**
 * Checks a filename for a specific extension and adds it if needed
 * @param filename filename to check
 */
char *checkFileExtension(char *filename)
{
    char *dot = getFileExtension(filename);
    char buf[1024];
    char *returnString = filename;
    if (!dot || !isEqual(dot, ".csv"))
    {
        strcpy(buf, filename);
        strcat(buf, ".csv");
        returnString = buf;
    }
    return returnString;
}

/**
 * Returns a file's extension and NULL if it does not have any
 * @param filename filename to check
 */
char *getFileExtension(char *filename)
{
    char *dot = strrchr(filename, '.');
    char *ext = NULL;
    if (dot)
    {
        ext = dot;
    }
    return ext;
}

