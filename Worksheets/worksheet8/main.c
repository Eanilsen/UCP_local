/**
 * main.c - Main file to test linked_list.c
 *
 * @author		Even A. Nilsen
 * @version		19.10.2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char *argv[])
{
    int i, input, value;
    
    /* Create an empty list */
    LinkedList *list = initialize();

    /* Populate the list by appending */
    for (i = 0; i < 3; i++)
    {
        append(list, i+1);
    }

    /* Populate the list by prepending */
    for (i = 3; i < 6; i++)
    {
        prepend(list, i+1);
    }

    /* Print list size */
    printf("List size: %d\n", list->size);

    /* Print all elements */
    printAll(list);

    /* Find and print a value */
    printf("Enter a value to search for: ");
    scanf("%d", &input);
    value = findValue(list, input);
    printf("Value found: %d\n", value);

    /* Find and delete a node */
    printf("Enter the value of a node you want to delete: ");
    scanf("%d", &input);
    deleteNode(list, input);
    
    /* Free each element of the list */
    printf("Deleting all elements\n");
    freeList(list);
    printf("List size: %d\n", list->size);

    /* Free the list */
    free(list);

    return 0;
}
