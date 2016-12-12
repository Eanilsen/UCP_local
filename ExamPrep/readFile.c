#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char search;
    char *text;
} Set;

Set *readFile(char *filename, int *aLen)
{
    FILE *fp = fopen(filename, "rb");
    int i, tLen, sLen;
    Set *s;
    if (fp == NULL || ferror(fp))
    {
        s = NULL;
    }
    else
    {
        fscanf(fp, "%d %d\n", aLen, &tLen);
        s = malloc(*aLen * sizeof(Set));
        for (i = 0; i < *aLen; i++)
        {
            s[i].text = malloc(tLen * sizeof(char));
            fscanf(fp, "%c ", &s[i].search);
            fgets(s[i].text, tLen+1, fp);
            fscanf(fp, "\n");
            sLen = strlen(s[i].text) - 1;
            if ((i > 0) && (s[i].text[sLen] == '\n'))
            {
                s[i].text[sLen] = '\0';
            }
        }
    }

    fclose(fp);
    return s;
}
int main(int argc, char *argv[])
{
    int i, aLen = 0;
    Set *s = readFile("rf.txt", &aLen);
    for (i = 0; i < aLen; i++)
    {
        printf("Search:%c Text:%s\n", s[i].search, s[i].text);
    }
    return 0;
}
