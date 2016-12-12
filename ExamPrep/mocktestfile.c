#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct
{
    char *code;
    double sharePrice;
    unsigned int totalShares;
    double totalAssetValue;
    double totalDebts;
} Company;

typedef struct
{
    int memSize;
    int assSize;
    Company *memberCompanies;
    Company *associateCompanies;
} Consortium;

Consortium *readConsortium(char *filename)
{
    FILE *fp = fopen(filename, "rb");
    int i, core, associate;
    Consortium *c = malloc(sizeof(Consortium));

    if (fp == NULL)
    {
        c = NULL;
    }
    else
    {
        fscanf(fp, "%d %d\n", &core, &associate);
        c->memberCompanies = malloc(core * sizeof(Company));
        c->associateCompanies = malloc(associate * sizeof(Company));
        c->memSize = 0;
        c->assSize = 0;

        for (i = 0; i < core; i++)
        {
            c->memberCompanies[i].code = malloc(3 * sizeof(char));
            fgets(c->memberCompanies[i].code, 4, fp);
            fscanf(fp, "%lf", &c->memberCompanies[i].sharePrice);
            fscanf(fp, "%u", &c->memberCompanies[i].totalShares);
            fscanf(fp, "%lf", &c->memberCompanies[i].totalAssetValue);
            fscanf(fp, "%lf\n", &c->memberCompanies[i].totalDebts);
            c->memSize++;
        }

        for (i = 0; i < associate; i++)
        {
            c->associateCompanies[i].code = malloc(3 * sizeof(char));
            fgets(c->associateCompanies[i].code, 4, fp);
            fscanf(fp, "%lf", &c->associateCompanies[i].sharePrice);
            fscanf(fp, "%u", &c->associateCompanies[i].totalShares);
            fscanf(fp, "%lf", &c->associateCompanies[i].totalAssetValue);
            fscanf(fp, "%lf\n", &c->associateCompanies[i].totalDebts);
            c->assSize++;
        }
        fclose(fp);
    }

    return c;
}

void writeNetWorth(char *filename, Consortium *cons)
{
    FILE *fp = fopen(filename, "wb");
    int i;
    double netWorth;

    if (fp == NULL)
    {
        perror("Cannot open file");
    }
    else
    {
        for (i = 0; i < cons->memSize; i++)
        {
            netWorth = (cons->memberCompanies[i].sharePrice * cons->memberCompanies[i].totalShares) +
                cons->memberCompanies[i].totalAssetValue - cons->memberCompanies[i].totalDebts;
            fprintf(fp, "%s:%12.2f\n", cons->memberCompanies[i].code, netWorth);
        }

        for (i = 0; i < cons->assSize; i++)
        {
            netWorth = (cons->associateCompanies[i].sharePrice * cons->associateCompanies[i].totalShares) +
                cons->associateCompanies[i].totalAssetValue - cons->associateCompanies[i].totalDebts;
            fprintf(fp, "%s:%12.2f\n", cons->associateCompanies[i].code, netWorth);
        }
        fclose(fp);
    }
}

/*int main(int argc, char *argv[])*/
/*{*/
    /*char input[1024], output[1024];*/
    /*int i;*/
    /*Consortium *cons;*/
    /*printf("Enter the input file: ");*/
    /*scanf("%s", input);*/
    /*printf("\nEnter the output file: ");*/
    /*scanf("%s", output);*/
    /*printf("\n");*/

    /*if ((cons = readConsortium(input)) == NULL)*/
    /*{*/
        /*printf("Input file could not be read.\n");*/
    /*}*/
    /*else*/
    /*{*/
        /*writeNetWorth(output, cons);*/
        /*for (i = 0; i < cons->memSize; i++)*/
        /*{*/
            /*free(cons->memberCompanies[i].code);*/
        /*}*/
        /*for (i = 0; i < cons->assSize; i++)*/
        /*{*/
            /*free(cons->associateCompanies[i].code);*/
        /*}*/

        /*free(cons->memberCompanies);*/
        /*free(cons->associateCompanies);*/
    /*}*/

    /*free(cons);*/
    /*return 0;*/
/*}*/

int main(int argc, char *argv[])
{
    int i, j;
    char outFile[1024];
    Consortium *cons;

    for (i = 1; i < argc; i++)
    {
        if ((cons = readConsortium(argv[i])) == NULL)
        {
            fprintf(stderr, "Input file could not be read.");
        }
        else
        {
            strcpy(outFile, argv[i]);
            strcat(outFile, ".out");
            writeNetWorth(outFile, cons);
            for (j = 0; j < cons->memSize; j++)
            {
                free(cons->memberCompanies[j].code);
            }
            for (j = 0; j < cons->assSize; j++)
            {
                free(cons->associateCompanies[j].code);
            }
            free(cons->memberCompanies);
            free(cons->associateCompanies);
        }
    }

    free(cons);
    return 0;
}
