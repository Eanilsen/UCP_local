/**
 * sorting_assignment.c - Assignment in Unix and C Programming (COMP1000)
 *
 * @author		Even A. Nilsen
 * @version		08.10.2016
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sorting_assignment.h"
#define TRUE 1

int main(int argc, char *argv[])
{
    getArgs(argc, argv);

    return 0;
}

/**
 * Handles command line arguments and flags
 * @param argc amount of arguments
 * @param argv command line arguments
 * @return 1 if error, 0 if ok
 */
int getArgs(int argc, char **argv)
{
    int idx = 0;
    char *inputFile = "";
    char *outputFile = "";

    for (idx = 1; idx < argc; ++idx)
    {
        if (isEqual(argv[idx], "-i") == TRUE && isEqual(inputFile, "") == TRUE)
        {
            idx++;
            inputFile = argv[idx];
            printf("Input file: %s\n", inputFile);
        }
        else if (isEqual(argv[idx], "-o") == TRUE && isEqual(outputFile, "") == TRUE)
        {
            idx++;
            outputFile = argv[idx];
            printf("Output file: %s\n", outputFile);
        }
        else
        {
            fprintf(stderr, "Unknown argument: %s\n", argv[idx]);
            exit(EXIT_FAILURE);
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

    if (equal == 0)
    {
        return TRUE;
    }
    else
    {
        return !TRUE;
    }
}
