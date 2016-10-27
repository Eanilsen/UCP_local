/**
 * insertion_sort.c - Generic insertion sort
 *
 * @author		Even A. Nilsen
 * @version		27.10.2016
 */
#include <stdio.h>
#include "insertion_sort.h"
#include <stdlib.h>
#define TRUE 1
#define FALSE !TRUE

int main(int argc, char *argv[])
{
    LinkedList *list = initialize();
    int i;
    append(list, (int*)3);
    append(list, (int*)6);
    append(list, (int*)1);
    append(list, (int*)5);
    append(list, (int*)2);
    append(list, (int*)4);

    for (i = 0; i < 6; i++)
    {
        printf("%d\n", (int*)findNode(list, i)->data);
    }

    insertionSort(list, &compareInt);

    for (i = 0; i < 6; i++)
    {
        printf("%d\n", (int*)findNode(list, i)->data);
    }
    return 0;
}
/**
 * Implementation of a generic insertion sort algorithm. It is supplied with 
 * a pointer to a linked list and a pointer to a compare function.
 * Returns 0 for success and a negative value for errors
 * @param list LinkedList
 * @param compare compare function
 */
int insertionSort(LinkedList *list, int (*compare)(void *elem1, void *elem2))
{
    LinkedListNode *current = list->head->next;
    LinkedListNode *temp = malloc(sizeof(LinkedListNode));
    int result = 0;
    int done = FALSE;
    while (current)
    {
        *temp = *current;
        while (!done && (*compare)(current->previous->data, current->data))
        {
            printf("Current P: %d\nCurrent D: %d\nCurrent N: %d\n", (int*)current->previous->data, (int*)current->data, (int*)current->next->data);
            printf("Temp P: %d\nTemp D: %d\nTemp N: %d\n", (int*)temp->previous->data, (int*)temp->data, (int*)temp->next->data);
            current->next->previous = current->previous;
            current->previous->next = current->next;
            current->next = current->previous;
            current->previous = current->previous->previous;
            if (!(*compare)(current->previous->data, current->data))
            {
                done = TRUE;
            }
        }
        current = temp->next;
        done = FALSE;
        /*printf("Current P: %d\nCurrent D: %d\nCurrent N: %d\n", (int*)current->previous->data, (int*)current->data, (int*)current->next->data);*/
        /*printf("Temp P: %d\nTemp D: %d\nTemp N: %d\n", (int*)temp->previous->data, (int*)temp->data, (int*)temp->next->data);*/
    }
    return result;
}

/**
 * Checks if one int value is smaller than the other
 * @param elem1 value to compare
 * @param elem2 value to compare
 */
int compareInt(void *elem1, void *elem2)
{
    int equal = FALSE;
    
    if (!elem1 || !elem2)
    {
        equal = FALSE;
    }
    else if ((int*)elem1 > (int*)elem2)
    {
        equal = TRUE;
    }
    
    return equal;
}

