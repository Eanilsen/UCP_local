#ifndef FILEREADER_H_3S2MU9XJ
#define FILEREADER_H_3S2MU9XJ

#include "linked_list.h"

void readFile(char *filename, LinkedList *list, int numRows);
char *getLine(FILE *fp);
int getNumRows(char *filename);

#endif /* end of include guard: FILEREADER_H_3S2MU9XJ */
