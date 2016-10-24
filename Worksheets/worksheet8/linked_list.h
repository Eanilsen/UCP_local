#ifndef LINKED_LIST_H_0SKXHUYL
#define LINKED_LIST_H_0SKXHUYL

typedef struct LinkedListNode
{
    int value;
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

void append(LinkedList *list, int val);

void prepend(LinkedList *list, int val);

void printAll(LinkedList *list);

void firstNode(LinkedList *list, int val);

void freeList(LinkedList *list);

LinkedListNode* findNode(LinkedList *list, int val);

void deleteNode(LinkedList *list, int val);

int findValue(LinkedList *list, int val);

#endif /* end of include guard: LINKED_LIST_H_0SKXHUYL */
