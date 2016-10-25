#ifndef LINKED_LIST_H_0SKXHUYL
#define LINKED_LIST_H_0SKXHUYL

#include "util.h"

typedef struct LinkedListNode
{
    char *data;
    struct LinkedListNode *next;
    struct LinkedListNode *previous;
} LinkedListNode;

typedef struct
{
    LinkedListNode *head;
    LinkedListNode *tail;
    int size;
} LinkedList;

LinkedList* initialize();

void append(LinkedList *list, char *data);

void prepend(LinkedList *list, char *data);

void printAll(LinkedList *list);

void firstNode(LinkedList *list, char *data);

void freeList(LinkedList *list);

LinkedListNode* findNode(LinkedList *list, int index);

void deleteNode(LinkedList *list, int index);

LinkedListNode *pop(LinkedList *list, int index);


#endif /* end of include guard: LINKED_LIST_H_0SKXHUYL */
