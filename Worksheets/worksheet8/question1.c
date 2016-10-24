/**
 * question1.c - Worksheet 6
 *
 * @author		Even A. Nilsen
 * @version		12.10.2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "question1.h"
#define TRUE 1
#define FALSE !TRUE
#define MAXLENGTH 100

int main(int argc, char *argv[])
{
    JournalEntry *entry = NULL;
    char *p;
    int index;
    if (argv[1])
    {
        index = strtol(argv[1], &p, 10);
        readFile("journal.txt", entry, index);
    }
    else
    {
        printf("Error\n");
    }
    return 0;
}

void readFile(char *filename, JournalEntry *entry, int index)
{
    int len, i;
    FILE *f = fopen(filename, "rb");

    if (f == NULL)
    {
        perror("Error opening the file");
    }
    else
    {
        fscanf(f, "%d", &len);
        entry = (JournalEntry*)malloc(len * sizeof(JournalEntry));
        for (i = 0; i < len; i++)
        {
            fscanf(f, "%d/%d/%d\n", &entry[i].date.day, &entry[i].date.month, &entry[i].date.year);
            entry[i].entry = (char*)malloc(MAXLENGTH * sizeof(char));
            fgets(entry[i].entry, MAXLENGTH+1, f);
        }
        if (ferror(f))
        {
            perror("Error reading from file");
        }

        if (index+1 > len)
        {
            printf("Index out of bounds. List size: %d\n", len);
        }
        else
        {
            printf("%d-%02d-%02d: %s\n", entry[index].date.year, entry[index].date.month, entry[index].date.day, entry[index].entry);
        }

        fclose(f);
    }
}

