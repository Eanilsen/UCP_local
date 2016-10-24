#ifndef FILEREADER_H_NL0MB5ZM
#define FILEREADER_H_NL0MB5ZM

typedef struct
{
    char **line;
    int arrSize;
} Strings;

char *getLine(FILE *fp);
void readFile(char *filename);

#endif /* end of include guard: FILEREADER_H_NL0MB5ZM */
