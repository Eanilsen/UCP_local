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
    readFile("journal.txt", entry);
    return 0;
}

void readFile(char *filename, JournalEntry *entry)
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
        entry = (JournalEntry*)malloc(len+1 * sizeof(JournalEntry));
        for (i = 0; i < len; i++)
        {
            fscanf(f, "%d/%d/%d", &entry[i].date.day, &entry[i].date.month, &entry[i].date.year);
            entry[i].entry = (char*)malloc(MAXLENGTH * sizeof(char));
            fgets(entry[i].entry, MAXLENGTH+1, f);
            printf("%d-%d-%d\n", entry[i].date.day, entry[i].date.month, entry[i].date.year);
            printf("%s\n", entry[i].entry);
        }
        if (ferror(f))
        {
            perror("Error reading from file");
        }
        fclose(f);
    }
}
