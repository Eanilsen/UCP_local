/**
 * sorting_assignment.c - Assignment in Unix and C Programming (COMP1000)
 *
 * @author		Even A. Nilsen
 * @version		08.10.2016
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "sorting_assignment.h"

int main(int argc, char *argv[])
{
    LinkedList *list = initialize();
    getArgs(argc, argv, list);
    freeList(list);
    free(list);

    return 0;
}

/**
 * Handles command line arguments and flags
 * @param argc amount of arguments
 * @param argv command line arguments
 * @param list LinkedList
 * @return 1 if error, 0 if ok
 */
int getArgs(int argc, char **argv, LinkedList *list)
{
    int idx = 0;
    char *inputFile = "";
    char *outputFile = "";

    if (argc != 5)
    {
        printf("Invalid number of arguments. Must be one input file and one output file.\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (idx = 1; idx < argc; ++idx)
        {
            if (isEqual(argv[idx], "-i") && isEqual(inputFile, ""))
            {
                idx++;
                inputFile = argv[idx];
                readFile(inputFile, list, getNumRows(inputFile));
            }
            else if (isEqual(argv[idx], "-o") && isEqual(outputFile, ""))
            {
                idx++;
                outputFile = argv[idx];
                writeToFile(outputFile, list);
            }
            else
            {
                fprintf(stderr, "Unknown argument: %s\n", argv[idx]);
                exit(EXIT_FAILURE);
            }
        }
    }
    return 0;
}

/**
 * Counts the amount of columns and returns the amount
 * @param list LinkedList
 * @return count
 */
int getColAmount(LinkedList *list)
{
    int count = 0;
    char *delim = ",";
    int len = strlen((char*)list->head->data);
    char *str = malloc(len * sizeof(char));
    str = strcpy(str, (char*)list->head->data);
    str = strtok(str, delim);
    while (str)
    {
        str = strtok(NULL, delim);
        count++;
    }
    return count;
}
