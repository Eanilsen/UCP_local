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
    str = strtok((char*)list->head->data, delim);
    while (str)
    {
        str = strtok(NULL, delim);
        count++;
    }
    return count;
}

/**
 * Splits the list data into tokens and prepares it for sorting
 * @param list LinkedList
 * @param colAmnt amount of columns
 */
void splitList(LinkedList *list, int colAmnt)
{
    LinkedList **listArray = malloc(colAmnt * sizeof(LinkedList*));
    int i, j, len;
    char *buf;
    for (i = 0; i < colAmnt; i++)
    {
        for (j = 0; j < colAmnt; j++)
        {
            len = strlen((char*)findNode(list, j)->data);
            listArray[i] = initialize();
        }
    }
}

