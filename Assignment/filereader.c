/**
 * filereader.c - Handles file input and output
 *
 * @author		Even A. Nilsen
 * @version		20.10.2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "filereader.h"
#define MAXLENGTH 1000

int main(int argc, char *argv[])
{
    readFile("test.csv");

    return 0;
}

void readFile(char *filename)
{
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL)
    {
        perror("Error opening the file");
    }
    else
    {
        int count = 0;
        int i;
        int length = MAXLENGTH;
        char *tmp = (char*)malloc(length * sizeof(char));
        Strings *str = malloc(sizeof(Strings));
        str->arrSize = 0;
        while (fscanf(fp, "%s", &tmp) != EOF)
        {
            if (count == length)
            {
                length *= 2;
                tmp = realloc(tmp, length * sizeof(char));
                if (tmp == NULL)
                {
                    fprintf(stderr, "Out of memory.\n");
                    exit(EXIT_FAILURE);
                }
            }
            str->line[count] = malloc(length * sizeof(char*));
            str->line[count] = getLine(fp);
            str->arrSize++;
        }
        if (ferror(fp))
        {
            perror("Error reading from the file");
        }
        for (i = 0; i < str->arrSize; i++)
        {
            printf("%s\n", str->line[i]);
        }
    }
    fclose(fp);
}

/**
 * Reads the contents of a file
 * @param filename name of the file
 */
char *getLine(FILE *fp)
{
    int count = 0;
    int length = MAXLENGTH;
    char *buf = malloc(length * sizeof(char));
    int ch = fgetc(fp);

    if (buf == NULL)
    {
        fprintf(stderr, "Out of memory\n");
    }
    while (ch != '\n' && ch != EOF)
    {
        if (count == length)
        {
            length *= 2;
            buf = realloc(buf, length * sizeof(char));
            if (buf == NULL)
            {
                fprintf(stderr, "Out of memory\n");
            }
        }
        buf[count] = ch;
        ch = fgetc(fp);
        count++;
    }
    buf[count] = '\0';

    return buf;
}

