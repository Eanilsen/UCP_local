#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char weekday[10];
    char name[101];
    struct {
        int hour;
        int min;
    } Start;
    struct {
        int hour;
        int min;
    } End;
} TVshow;

typedef struct
{
    int numShows;
    char name[11];
    TVshow *shows;
} Channel;

typedef struct
{
    int numChannels;
    Channel *channels;
} Guide;

Guide *readTV(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    int i, j;
    Guide *g = malloc(sizeof(Guide));

    if (fp == NULL)
    {
        g = NULL;
    }
    else
    {
        fscanf(fp, "%d", &g->numChannels);
        g->channels = malloc(g->numChannels * sizeof(Channel));
        for (i = 0; i < g->numChannels; i++)
        {
            fscanf(fp, " %s %d", g->channels[i].name, &g->channels[i].numShows);
            g->channels[i].shows = malloc(g->channels[i].numShows * sizeof(TVshow));
        }
        fscanf(fp, "\n");
        for (i = 0; i < g->numChannels; i++)
        {
            for (j = 0; j < g->channels[i].numShows; j++)
            {
                fscanf(fp, " %d:%d", &g->channels[i].shows[j].Start.hour,
                        &g->channels[i].shows[j].Start.min);
                fscanf(fp, " %d:%d", &g->channels[i].shows[j].End.hour,
                        &g->channels[i].shows[j].End.min);
                fscanf(fp, " %s", g->channels[i].shows[j].weekday);
                fscanf(fp, " %[^\t\n]\n", g->channels[i].shows[j].name);
            }
        }
        fclose(fp);
    }
    return g;
}

void whatsOn(Guide *g, char weekday[4], char time[6])
{
    int i, j;
    char startTime[6], endTime[6];

    for (i = 0; i < g->numChannels; i++)
    {
        for (j = 0; j < g->channels[i].numShows; j++)
        {
            if ((strcmp(weekday, g->channels[i].shows[j].weekday)) == 0)
            {
                sprintf(startTime, "%d:%d", g->channels[i].shows[j].Start.hour,
                        g->channels[i].shows[j].Start.min);
                sprintf(endTime, "%d:%d", g->channels[i].shows[j].End.hour,
                        g->channels[i].shows[j].End.min);
                if ((strcmp(time, startTime)) <= 0 || (strcmp(time, endTime)) 
                        >= 0)
                {
                    printf("Channel: %s\n", g->channels[i].name);
                    printf("Show: %s\n", g->channels[i].shows[j].name);
                    printf("\n");
                }
            }
        }
    }
}

int main(int argc, char *argv[])
{
    int i;
    Guide *g;

    if (argc != 4)
    {
        fprintf(stderr, "Wrong number of arguments.");
    }
    else
    {
        if ((g = readTV(argv[1])) == NULL)
        {
            fprintf(stderr, "Input file could not be read.");
        }
        else
        {
            whatsOn(g, argv[2], argv[3]);
            for (i = 0; i < g->numChannels; i++)
            {
                free(g->channels[i].shows);
            }
            free(g->channels);
        }
        free(g);
    }
    return 0;
}
