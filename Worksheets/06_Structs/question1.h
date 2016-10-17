#ifndef QUESTION1_H_WBEU2HZQ
#define QUESTION1_H_WBEU2HZQ

typedef struct
{
    char *date;
    char *entry;
} JournalEntry;

void readFile(char *filename, JournalEntry *entry);

#endif /* end of include guard: QUESTION1_H_WBEU2HZQ */
