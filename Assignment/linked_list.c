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
void append(LinkedList *list, char *data)
{
    if (list->size == 0)
    {
        firstNode(list, data);
    }
    else
    {
        LinkedListNode *node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        node->data = data;
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
void prepend(LinkedList *list, char *data)
{
    if (list->size == 0)
    {
        firstNode(list, data);
    }
    else
    {
        LinkedListNode *node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        node->data = data;
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
void firstNode(LinkedList *list, char *data)
{
    if (list->size == 0)
    {
        LinkedListNode *node = (LinkedListNode*)malloc(sizeof(LinkedListNode));
        node->data = data;
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
    LinkedListNode *current = NULL;
    current = list->head;
    while (current != NULL)
    {
        printf("Current: %p\n", current);
        printf("Value: %s\n", current->data);
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
    int i, size = list->size;
    LinkedListNode *current = list->head;
    for (i = 0; i < size; i++)
    {
        list->head = current->next;
        free(current->data);
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
LinkedListNode* findNode(LinkedList *list, int index)
{
    int i = 0;
    LinkedListNode *node = NULL;

    if (list->size != 0 && index < list->size)
    {
        LinkedListNode *current = list->head;
        while (current != NULL && index > i)
        {
            current = current->next;
            i++;
        }
        node = current;
    }

    return node;
}

/**
 * Searches the list for a node and deletes it if found
 * @param list LinkedList
 * @param val value to search for 
 */
void deleteNode(LinkedList *list, int index)
{
    LinkedListNode *node = findNode(list, index);
    if (node != NULL)
    {
        printf("Deleting node: %p with value: %s\n", node, node->data);
        node->previous->next = node->next;
        node->next->previous = node->previous;
        free(node->data);
        free(node);
        list->size--;
        printf("List size now: %d\n", list->size);
    }
    else
    {
        printf("Node with index: %d was not found.\n", index);
    }
}

/**
 * Searches for a node given an index. Removes it from the list and returns it
 * @param list LinkedList
 * @param index Node to pop
 * @return node
 */
LinkedListNode *pop(LinkedList *list, int index)
{
    LinkedListNode *node = NULL;
    if ((node = findNode(list, index)) != NULL && index != 0 &&
            index < list->size-1)
    {
        node->next->previous = node->previous;
        node->previous->next = node->next;
        list->size--;
    }
    else if ((node = findNode(list, index)) != NULL && index == 0)
    {
        list->head = node->next;
        list->head->previous = NULL;
        list->size--;
    }
    else if ((node = findNode(list, index)) != NULL && index == list->size-1)
    {
        list->tail = node->previous;
        list->tail->next = NULL;
        list->size--;
    }
    else
    {
        printf("Node with index: %d was not found\n", index);
    }

    return node;
}

