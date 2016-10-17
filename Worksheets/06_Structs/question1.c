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
    char buf[MAXLENGTH];

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
            fgets(buf, MAXLENGTH+1, f);
            entry[i].date = buf;
            fgets(buf, MAXLENGTH+1, f);
            entry[i].entry = buf;
            printf("%s\n", entry[i].date);
            printf("%s\n", entry[i].entry);
        }

        if (ferror(f))
        {
            perror("Error reading from file");
        }
        fclose(f);
    }
}
