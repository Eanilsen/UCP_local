#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    double x;
    double y;
} Point;

typedef struct
{
    char *commandType;
    union {
        struct {
            char colourCode;
            Point *p;
            double radius;
        } Circle;
        struct{
            char colourCode;
            Point *start;
            Point *end;
        } Line;
    } Shape;
} Command;

typedef struct
{
    int numCommands;
    Command *command;
} Drawing;

Drawing *loadDrawing(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    int i;
    char buf[1024];
    Drawing *d = malloc(sizeof(Drawing));

    if (fp == NULL)
    {
        d = NULL;
    }
    else
    {
        fscanf(fp, "%d\n", &d->numCommands);
        d->command = malloc(d->numCommands * sizeof(Command));
        for (i = 0; i < d->numCommands; i++)
        {
            fscanf(fp, "%s", d->command[i].commandType);
            if ((strcmp(buf, "LINE")) == 0)
            {
                d->command[i].commandType = "Line";
                fscanf(fp, "(%lf, %lf)", &d->command[i].Shape.Line.start->x,
                        &d->command[i].Shape.Line.start->y);
                fscanf(fp, "-(%lf, %lf)", &d->command[i].Shape.Line.end->x,
                        &d->command[i].Shape.Line.end->y);
                fscanf(fp, "%c\n", &d->command[i].Shape.Line.colourCode);
            }
            else
            {
                d->command[i].commandType = "Circle";
                fscanf(fp, "(%lf, %lf):%lf", &d->command[i].Shape.Circle.p->x,
                        &d->command[i].Shape.Circle.p->y,
                        &d->command[i].Shape.Circle.radius);
                fscanf(fp, "%c\n", &d->command[i].Shape.Circle.colourCode);
            }
        }
        fclose(fp);
    }
    return d;
}

int main(int argc, char *argv[])
{
    int i;
    Drawing *d = loadDrawing("drawing.txt");

    for (i = 0; i < d->numCommands; i++)
    {
        printf("Shape: %s\n", d->command[i].commandType);
        if ((strcmp(d->command[i].commandType, "Line")) == 0)
        {
            printf("Coordinates: (%.1f, %.1f)-(%.1f, %.1f)\n",
                    d->command[i].Shape.Line.start->x,
                    d->command[i].Shape.Line.start->y, d->command[i].Shape.Line.end->x,
                    d->command[i].Shape.Line.end->y);
            printf("Colour Code: %c\n", d->command[i].Shape.Line.colourCode);
        }
        else
        {
            printf("Coordinates: (%.1f, %.1f)\n", d->command[i].Shape.Circle.p->x,
                    d->command[i].Shape.Circle.p->y);
            printf("Radius: %.1f\n", d->command[i].Shape.Circle.radius);
            printf("Colour Code: %c\n", d->command[i].Shape.Circle.colourCode);
        }
    }
    return 0;
}
