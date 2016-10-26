/**
 * filereader.c - Handles file input and output
 *
 * @author		Even A. Nilsen
 * @version		25.10.2016
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include "filereader.h"
#define TRUE 1
#define FALSE !TRUE
#define MAXLENGTH 1000

void readFile(char *filename, LinkedList *list, int numRows)
{
    FILE *fp = fopen(filename, "rb");
    int i;

    if (fp == NULL)
    {
        perror("Error opening the file");
    }
    else
    {
        for (i = 0; i < numRows; i++)
        {
            append(list, getLine(fp));
        }
        if (ferror(fp))
        {
            perror("Error reading from the file");
        }
    }
    fclose(fp);
}

/**
 * Reads a line from a file given a file pointer
 * @param fp file pointer
 */
char *getLine(FILE *fp)
{
    int count = 0;
    int length = MAXLENGTH;
    char *buf = malloc(length * sizeof(char));
    int ch = fgetc(fp);

    if (buf == NULL)
    {
        fprintf(stderr, "Out of memory.\n");
        exit(EXIT_FAILURE);
    }
    while (ch != '\n' && ch != EOF)
    {
        if (count == length)
        {
            length *= 2;
            buf = realloc(buf, length * sizeof(char));
            if (buf == NULL)
            {
                fprintf(stderr, "Out of memory.\n");
                exit(EXIT_FAILURE);
            }
        }
        buf[count] = ch;
        ch = fgetc(fp);
        count++;
    }
    buf[count] = '\0';

    return buf;
}

/**
 * Counts the number of rows from a file
 * @param filename name of file
 */
int getNumRows(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    int count = 0;
    int ch;
    if (fp == NULL)
    {
        perror("Error opening the file.");
        exit(EXIT_FAILURE);
    }
    else
    {
        while (!feof(fp))
        {
            ch = fgetc(fp);
            if (ch == '\n')
            {
                count++;
            }
            
        }
        if (ferror(fp))
        {
            perror("Error reading from the file.");
        }
    }
    fclose(fp);
    
    return count;
}

/**
 * Writes the contents of a list to an output file
 */
void writeToFile(char *filename, LinkedList *list)
{
    FILE *fp = fopen(filename, "wb");
    LinkedListNode *node;
    int i;
    if (fp == NULL)
    {
        perror("Error opening the file.");
        exit(EXIT_FAILURE);
    }
    else
    {
        for (i = 0; i < list->size; i++)
        {
            node = findNode(list, i);
            fputs(node->data, fp);
            fputc('\n', fp);
        }
        if (ferror(fp))
        {
            perror("Error writing to file.");
        }
    }
    fclose(fp);
}

