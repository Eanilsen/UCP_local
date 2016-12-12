#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int population;
    char type;
} Cell;

typedef struct
{
    int width;
    int length;
} Rectangle;

typedef struct
{
    char desc[128];
    char date[9];
    Rectangle *cellSize;
    Rectangle *gridSize;
    Cell **grid;
} Record;

Record *loadLand(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    int i, j;
    Record *r = malloc(sizeof(Record));

    if (fp == NULL)
    {
        r = NULL;
    }
    else
    {
        fscanf(fp, "%[^\t\n]\n", r->desc);
        fscanf(fp, "%s\n", r->date);
        r->cellSize = malloc(sizeof(Rectangle));
        r->gridSize = malloc(sizeof(Rectangle));
        fscanf(fp, "%dx%d\n", &r->cellSize->width, &r->cellSize->length);
        fscanf(fp, "%dx%d\n", &r->gridSize->width, &r->gridSize->length);
        r->grid = malloc(r->gridSize->length * sizeof(Cell*));
        for (i = 0; i < r->gridSize->length; i++)
        {
            r->grid[i] = malloc(r->gridSize->width * sizeof(Cell));
            for (j = 0; j < r->gridSize->width; j++)
            {
                fscanf(fp, "%d%c", &r->grid[i][j].population, &r->grid[i][j].type);
            }
            fscanf(fp, "\n");
        }
        fclose(fp);
    }
    return r;
}

void analyseLand(Record *r, double *popDensity, char *urban)
{
    int totalCells = r->gridSize->length * r->gridSize->width;
    int numUrban = 0, numPop = 0, i, j;

    for (i = 0; i < r->gridSize->length; i++)
    {
        for (j = 0; j < r->gridSize->width; j++)
        {
            if (r->grid[i][j].type == 'U')
            {
                numUrban++;
            }
            numPop += r->grid[i][j].population;
        }
    }
    *popDensity = numPop / totalCells;
    sprintf(urban, "%d", numUrban);
}

int main(int argc, char *argv[])
{
    Record *r;
    double pop;
    char urban;
    int i;

    if (argc != 2)
    {
        fprintf(stderr, "Invalid number of arguments.\n");
    }
    else
    {
        if ((r = loadLand(argv[1])) == NULL)
        {
            fprintf(stderr, "Input file could not be read.\n");
        }
        else
        {
            analyseLand(r, &pop, &urban);
            printf("Population Density: %.2f\n", pop);
            printf("Number of Urban: %c\n", urban);
            for (i = 0; i < r->gridSize->length; i++)
            {
                free(r->grid[i]);
            }
            free(r->grid);
        }
    }

    free(r);
    return 0;
}
