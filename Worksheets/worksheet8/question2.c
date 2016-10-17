/**
 * question2.c - Worksheet6
 *
 * @author		Even A. Nilsen
 * @version		12.10.2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "question2.h"

int main(int argc, char *argv[])
{
    int i;
    LinkedList *list = initialize();

    for (i = 0; i < 5; i++)
    {
        newNode(list, i+1);
    }
    printValue(list->head);
    free(list);
    return 0;
}

/**
 * Initialize the list and point head to the first node
 * @param list LinkedList
 */
LinkedList* initialize()
{
    LinkedList *list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

/**
 * Creates a new node and inserts it at the start
 * @param list LinkedList
 * @param val value assigned to node
 */
void newNode(LinkedList *list, int val)
{
    LinkedListNode *node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    if (list->head == NULL)
    {
        node->value = val;
        node->next = NULL;
        list->head = node;
        printf("Value of first node: %d\n", list->head->value);
    }
    else
    {
        node->value = val;
        node->next = list->head;
        list->head = node;
        printf("Value of node: %d\n", list->head->value);
    }
}

/**
 * Prints all values in the linked list recursively
 * @param head head of LinkedList
 */
void printValue(LinkedListNode *head)
{
    LinkedListNode *current = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    current = head;
    if (current == NULL)
    {
        printf("List is empty\n");
        return;
    }
    if (current->next != NULL)
    {
        printValue(current->next);
    }
    printf("Print %p -> %p %d\n", current, current->next, current->value);
    /*while (current != NULL)*/
    /*{*/
        /*printf("%d\n", current->value);*/
        /*current = current->next;*/
    /*}*/
}
