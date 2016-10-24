/**
 * filereader.c - Handles file input and output
 *
 * @author		Even A. Nilsen
 * @version		20.10.2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "filereader.h"

/**
 * Reads the contents of a file
 * @param filename name of the file
 */
void readFile(char *filename)
{
    int i;
    FILE *f = fopen(filename, "rb");

    if (f == NULL)
    {
        perror("Error opening the file");
    }
    else
    {
        if (ferror(f))
        {
            perror("Error reading from the file");
        }
    }
    fclose(f);
}

