#ifndef QUESTION1_H_WBEU2HZQ
#define QUESTION1_H_WBEU2HZQ

typedef struct
{
    char *entry;
    struct
    {
        int day;
        int month;
        int year;
    } date;
} JournalEntry;

void readFile(char *filename, JournalEntry *entry, int index);

#endif /* end of include guard: QUESTION1_H_WBEU2HZQ */
