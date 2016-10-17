/**
 * linked_list.c - Implementation of a linked list data structure
 *
 * @author		Even A. Nilsen
 * @version		12.10.2016
 */
#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#define TRUE 1
#define FALSE !TRUE

int main(int argc, char *argv[])
{
    int i, input;
    LinkedList *list = initialize();
    LinkedListNode *node = NULL;

    freeList(list);
    free(list);
    return 0;
}

/**
 * Initialize the list, set the size to 0 and point head to NULL
 * @return list
 */
LinkedList* initialize()
{
    LinkedList *list;
    list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

/**
 * Creates a new node and appends it to the list
 * @param list LinkedList
 * @param val value assigned to node
 */
void append(LinkedList *list, int val)
{
    if (list->size == 0)
    {
        firstNode(list, val);
    }
    else
    {
        LinkedListNode *node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        node->value = val;
        node->previous = list->tail;
        node->next = NULL;
        list->tail->next = node;
        list->tail = node;
        list->size++;
    }
}

/**
 * Creates a new node and prepends it to the list
 * @param list LinkedList
 * @param val value assigned to the node
 */
void prepend(LinkedList *list, int val)
{
    if (list->size == 0)
    {
        firstNode(list, val);
    }
    else
    {
        LinkedListNode *node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        node->value = val;
        node->next = list->head;
        node->previous = NULL;
        list->head->previous = node;
        list->head = node;
        list->size++;
    }
}

/**
 * Creates the first node in the list if the list is empty
 * @param list LinkedList
 * @param val value assigned to the node
 */
void firstNode(LinkedList *list, int val)
{
    if (list->size == 0)
    {
        LinkedListNode *node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        node->value = val;
        node->previous = NULL;
        node->next = NULL;
        list->head = node;
        list->tail = node;
        list->size++;
    }
    else
    {
        printf("The list is not empty.\n");
    }
}

/**
 * Prints all values in the linked list from head to tail
 * @param list LinkedList
 */
void printAll(LinkedList *list)
{
    LinkedListNode *current = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    current = list->head;
    while (current != NULL)
    {
        printf("Current: %p\n", current);
        printf("Value: %d\n", current->value);
        printf("Next: %p -> %p\n", current, current->next);
        printf("Previous: %p -> %p\n", current, current->previous);
        printf("----------\n");
        current = current->next;
    }
    if (list->size == 0)
    {
        printf("List is empty\n");
    }
}

/**
 * Frees every node in the list
 * @param list LinkedList
 */
void freeList(LinkedList *list)
{
    LinkedListNode *current = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    current = list->head;
    while (current != NULL)
    {
        list->head = current->next;
        free(current);
        current = list->head;
        list->size--;
    }
}

/**
 * Searches the linked list for a value and returns the node if found
 * @param list LinkedList
 * @param val value to search for
 */
LinkedListNode* findNode(LinkedList *list, int val)
{
    int found = FALSE;
    LinkedListNode *node = NULL;

    if (list->size != 0)
    {
        LinkedListNode *current = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        current = list->head;
        while (current != NULL && found == FALSE)
        {
            if (current->value == val)
            {
                node = current;
                found = TRUE;
            }
            current = current->next;
        }
    }

    if (node == NULL)
    {
        printf("Node was not found. Exiting\n");
        exit(EXIT_FAILURE);
    }
    return node;
}

/**
 * Searches the list for a node and deletes it if found
 * @param list LinkedList
 * @param val value to search for 
 */
void deleteNode(LinkedList *list, int val)
{
    LinkedListNode *node = findNode(list, val);
    printf("Deleting node: %p with value: %d\n", node, node->value);
    free(node);
    list->size--;
    printf("List size now: %d\n", list->size);
}

